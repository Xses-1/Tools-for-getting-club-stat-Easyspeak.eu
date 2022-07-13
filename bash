cat meeting_list.php | grep view_meeting.php?t= >> meetings_links


w3m -dump https://tmclub.eu/view_meeting.php?t=182074 | echo -n $(grep "Member (") >> club_stats
echo -n "  " >> club_stats
w3m -dump https://tmclub.eu/view_meeting.php?t=182074 | grep -c Speaker >> club_stats





w3m -dump https://tmclub.eu/view_meeting.php?t=182074 | echo -n $(grep 'Member (') >> club_stats; echo -n '  ' >> club_stats; w3m -dump https://tmclub.eu/view_meeting.php?t=182074 | grep -c Speaker >> club_stats;
