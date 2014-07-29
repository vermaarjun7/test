import urllib2
import matplotlib.animation as animation
import numpy as np
import matplotlib
import pylab
import datetime
import matplotlib.pyplot as plt
import matplotlib.ticker as mticker
import matplotlib.dates as mdates
from matplotlib.finance import candlestick
matplotlib.rcParams.update({'font.size': 9})

eachStock = 'AAPL'
#function to calculate moving average
def movingAverage(values, window):
    weights = np.repeat(1.0, window)/window
    smas = np.convolve(values, weights, 'valid')
    return smas

def rsiFunc(prices, n=14):
    deltas = np.diff(prices)
    seed = deltas[:n+1]
    up = seed[seed>=0].sum()/n
    down = -seed[seed<0].sum()/n
    rs = up/down
    rsi = np.zeros_like(prices)
    rsi[:n] = 100. - 100./(1.+rs)

    for i in range(n, len(prices)):
        delta = deltas[i-1]
        if delta > 0:
            upval = delta
            downval = 0.
        else:
            upval = 0.
            downval = -delta
        up = (up*(n-1)+ upval)/n
        down = (down*(n-1)+downval)/n
        rs = up/down
        rsi[i] = 100. - 100./(1.+rs)
    return rsi

def ExpMovingAverage(values, window):#gives more importance to recent data
    weights = np.exp(np.linspace(-1., 0., window))
    weights /= weights.sum()
    a = np.convolve(values, weights, mode='full')[:len(values)]
    a[:window] = a[window]
    return a


def computeMACD(x, slow=26, fast=12):
    '''
    macd line = 12ema - 26ema
    signal line = 9ema of the macd line
    histogram = macd line - signal line
    '''

    emaslow = ExpMovingAverage(x, slow)
    emafast = ExpMovingAverage(x, fast)
    return emaslow, emafast, emafast-emaslow


#momentum oscillator
#biggest part it tells is that , whether a stock is going to be over bought or over sold
#above 70 is that it's over boughT and below 30 tells that it is oversold
#for most RSI hit above 70 or below 30 , only a handful of time , at most in a year
#untill that stock is very volatile



def graphData(stock, MA1, MA2):
    fig.clf()#clears the fig everytime
    try:
        try:
            print 'pulling data on ', stock
            urlToVisit = 'http://chartapi.finance.yahoo.com/instrument/1.0/'+stock+'/chartdata;type=quote;range=1d/csv'
            stockFile = []
            try:
                sourceCode = urllib2.urlopen(urlToVisit).read()
                splitSource = sourceCode.split('\n')
                for eachLine in splitSource:
                    splitLine = eachLine.split(',')
                    fixMe = splitLine[0]
                    if len(splitLine) == 6:
                        if 'values' not in eachLine:
                            fixed = eachLine.replace(fixMe, str(datetime.datetime.fromtimestamp(int(fixMe)).strftime('%Y-%m-%d %H:%M:%S')))
                            stockFile.append(fixed)
                            # stockFile.append(eachLine)
            except Exception, e:
                print str(e), 'failed to organize pulled data'

        except Exception, e:
            print str(e),'failed to pull price data'
        date , closep, highp, lowp, openp, volume = np.loadtxt(stockFile,delimiter=',',unpack=True,
                                                               converters={0: mdates.strpdate2num('%Y-%m-%d %H:%M:%S')})
        x = 0
        y = len(date)
        candleAr = []
        while x < y:
            appendLine = date[x],openp[x],closep[x],highp[x],lowp[x],volume[x]
            candleAr.append(appendLine)
            x += 1

        Av1 = movingAverage(closep, MA1)
        Av2 = movingAverage(closep, MA2)

        SP = len(date[MA2 - 1:])

        label1 = str(MA1)+' SMA'
        label2 = str(MA2)+' SMA'





        ax1 = plt.subplot2grid((6,4), (1,0), rowspan=4, colspan=4, axisbg='#07000d')
        candlestick(ax1, candleAr[-SP:], width=0.0005, colorup='#53C156', colordown='#ff1717')

        ax1.plot(date[-SP:], Av1[-SP:], '#e1edf9', label= label1, linewidth = 2)
        ax1.plot(date[-SP:], Av2[-SP:], '#4ee6fd', label= label2, linewidth = 2)

        ax1.grid(True, color='w')
        ax1.xaxis.set_major_locator(mticker.MaxNLocator(10))
        plt.gca().yaxis.set_major_locator(mticker.MaxNLocator(prune='upper'))
        ax1.yaxis.label.set_color("w")
        ax1.spines['bottom'].set_color("#5998ff")
        ax1.spines['top'].set_color("#5998ff")
        ax1.spines['right'].set_color("#5998ff")
        ax1.spines['left'].set_color("#5998ff")
        ax1.tick_params(axis='y',colors='w')
        ax1.tick_params(axis='x',colors='w')
        plt.ylabel('Stock Price & Volume', color='w')



        maLeg = plt.legend(loc=9, ncol=2, prop={'size':7}, fancybox=True)
        maLeg.get_frame().set_alpha(0.4)
        textEd = pylab.gca().get_legend().get_texts()
        pylab.setp(textEd[0:5], color='w')


        ax0 = plt.subplot2grid((6,4), (0,0), sharex = ax1,rowspan=1, colspan=4, axisbg='#07000d')
        rsiColor = '#c1f9f7'
        poscol = '#386d13'
        negcol = '#8f2020'
        rsi = rsiFunc(closep)
        ax0.plot(date[-SP:],rsi[-SP:],rsiColor,linewidth=1.5)
        ax0.axhline(70, color = negcol)
        ax0.axhline(30, color = poscol)
        ax0.fill_between(date[-SP:],rsi[-SP:], 70, where=(rsi[-SP:]>=70), facecolor=negcol, edgecolor=negcol)
        ax0.fill_between(date[-SP:],rsi[-SP:], 30, where=(rsi[-SP:]<=30), facecolor=poscol, edgecolor=poscol)
        ax0.xaxis.set_major_formatter(mdates.DateFormatter('%Y-%m-%d'))
        ax0.spines['bottom'].set_color("#5998ff")
        ax0.spines['top'].set_color("#5998ff")
        ax0.spines['right'].set_color("#5998ff")
        ax0.spines['left'].set_color("#5998ff")
        ax0.text(0.015, 0.95, 'RSI(14)', va='top', color='w', transform=ax0.transAxes)
        ax0.set_ylim(0, 100)
        ax0.tick_params(axis='x',colors='w')
        ax0.tick_params(axis='y',colors='w')
        ax0.set_yticks([30, 70])
        ax0.yaxis.label.set_color("w")
        # plt.gca().yaxis.set_major_locator(mticker.MaxNLocator(prune='lower'))
        # plt.ylabel('RSI')


        volumeMin = 0

        ax1v = ax1.twinx()
        ax1v.fill_between(date[-SP:], volumeMin, volume[-SP:], facecolor='#00ffe8', alpha=.5)

        ax1v.axes.yaxis.set_ticklabels([])
        ax1v.grid(False)
        ax1v.spines['bottom'].set_color("#5998ff")
        ax1v.spines['top'].set_color("#5998ff")
        ax1v.spines['right'].set_color("#5998ff")
        ax1v.spines['left'].set_color("#5998ff")
        ax1v.set_ylim(0, 4*volume.max())
        ax1v.tick_params(axis='x',colors='w')
        ax1v.tick_params(axis='y',colors='w')


        ax2 = plt.subplot2grid((6,4), (5,0), sharex=ax1, rowspan=1, colspan=4, axisbg='#07000d')
        nslow = 26
        nfast = 12
        nema = 9

        emaslow, emafast, macd = computeMACD(closep)
        ema9 = ExpMovingAverage(macd, nema)
        ax2.plot(date[-SP:], macd[-SP:], color='#4ee6fd', lw=2)
        ax2.plot(date[-SP:], ema9[-SP:],color='#e1edf9', lw=2)
        fillColor = '#00ffe8'
        ax2.fill_between(date[-SP:], macd[-SP:]-ema9[-SP:], 0, alpha=0.5, facecolor=fillColor)
        # plt.gca().yaxis.set_major_locator(mticker.MaxNLocator(prune='upper'))

        ax2.xaxis.set_major_formatter(mdates.DateFormatter('%Y-%m-%d'))
        ax2.spines['bottom'].set_color("#5998ff")
        ax2.spines['top'].set_color("#5998ff")
        ax2.spines['right'].set_color("#5998ff")
        ax2.spines['left'].set_color("#5998ff")
        ax2.text(0.015, 0.95, 'MACD 12,26,9', va='top', color='w', transform=ax2.transAxes)
        ax2.yaxis.set_major_locator(mticker.MaxNLocator(nbins=5, prune='upper'))
        # ax2.set_ylim(0, 4*volume.max())
        ax2.tick_params(axis='x',colors='w')
        ax2.tick_params(axis='y',colors='w')
        # plt.ylabel('MACD',color='w')

        for label in ax2.xaxis.get_ticklabels():
            label.set_rotation(45)



        plt.suptitle(stock, color='w')
        plt.setp(ax0.get_xticklabels(), visible=False)
        plt.setp(ax1.get_xticklabels(), visible=False)
        plt.subplots_adjust(left=.09, bottom=.14, right=.94, top=.95, wspace=.20, hspace=0)
        # plt.show()
        # fig.savefig('example.png', format = 'png',facecolor=fig.get_facecolor())

    except Exception, e:
            print 'main loop',str(e)

fig = plt.figure(facecolor='#07000d')

def animate(i):
    graphData(stockToUse, MA1, MA2)



def main():
        while True:
            global stockToUse
            stockToUse = raw_input('Specify the Stock to chart ')
            global MA1
            MA1 = 20
            global MA2
            MA2 = 50
            # graphData(stockToUse, 20, 200)
            ani = animation.FuncAnimation(fig, animate, interval = 1000)
            plt.show()


if __name__ == '__main__':
    main()

