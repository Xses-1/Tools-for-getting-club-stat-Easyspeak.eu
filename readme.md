# Data Scrapper for the Toastmaster's Easy Speak - tmclub.eu

This set of tools allows you to extract all the statistics of your club from the tmclub.eu aka EasySpeak, so now you can follow the performance of your board in relation with all the previous bards.

The data that you can extract are:
<ol>
<li> The amount of member during every historical meeting </li>
<li> The amount of total member in the club for every meeting </li> 
<li> Changes of those 2 above in relation with the previous meeting </li>
<li> Amount of speeches given during every meeting </li>
</ol>

And naturally every spreadsheet program can calculate predicitons and avereages out of that, and make graph as well.

Here are some examples:

<img src="https://github.com/Xses-1/Tools-for-getting-club-stat-Easyspeak.eu/blob/main/pictures/chart1.png">
<br>
<img src="https://github.com/Xses-1/Tools-for-getting-club-stat-Easyspeak.eu/blob/main/pictures/chart2.png">
<br>


## Dependencies

You need Linux, w3m browser, make, and g++:
<br>
```
sudo apt install w3m make g++
```

## Preparation

First you need to obtain a html file of the subsite of tmclub.eu that has list of all the meetings of your club. Login to tmclub.eu then go Meetings --> Meetings List --> right click --> Save Page As --> save to the meetings directory.


Once that is done then you can use the getting_links.sh script to extact the list of the meetings from the html file.

Lastly the meeting_links file has to be manually modified so it has the same structure as the refrence one (meetings_links.ref). Just use a text editor and get rid of the excessive stuff.

## Execution

First open w3m rowser and login to tmclub.eu.

```
w3m tmclub.eu
```

Don't forget to select "remember me" field. Our programs will use that to acess tmclub.eu.


Finally, just run RunME.sh and everything should happen automatically. Your data will be output to the files in the main directory (filtered output) and in data_processor/work_file (nonfiltered output). These data can be easily copy pasted to your favourite spreadsheet editor.
```
./RunME.sh
```



Good luck, have fun :)
