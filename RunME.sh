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
cat data/club_stats | ./processor.o

# Now the data goes into the biquad filter that filters it so it's
# much easier to read in interpret. The only data that don't have
# to be filtered because it's already not changing drastically enough
# for it to make nay difference is the amount of member and its change.
cat data_processor/work_files/percentages | ./filter.o >> filtered_attendance
cat data_processor/work_files/speeches | ./filter.o >> filtered_speeches
cat data_processor/work_files/dp | ./filter.o >> filtered_change_attendance

# This is just cleaning of the executable files
make clean
