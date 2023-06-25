#!/bin/bash

# Compile
make

# This scrapes the datat provided in meetings/meetings_links file and
# outputs it to data/club_stats I also outputs the amount of meetings
# to data/meetings_amount.
./scraper.o

# This takes data/club_stats as terminal input and then splits it into
# separate files with every column of data, so it can be copied to
# spreadsheet. It also calculates change of percentage of members that
# attended the meeting and change of amount of members.


# Clean
make clean
