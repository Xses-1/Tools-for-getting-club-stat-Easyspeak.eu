#include <bits/stdc++.h>

int main () {

	std::vector<int> index, attenders, members, speeches, percentage, delta_percentage, delta_members;
	int old_percentage, old_members, length, temp1, temp2, temp3, temp4;
	std::string base_command, cpercentages, cmembers, cdp, cdm, cspeeches;

	base_command = "echo '";

	std::cin >> length;

	for (int i = 0; i < length; i++) {

		std::cin >> temp1;
		std::cin >> temp2;
		std::cin >> temp3;
		std::cin >> temp4;

		index.push_back (temp1);
		attenders.push_back (temp2);
		members.push_back (temp3);
		speeches.push_back (temp4);

		percentage.push_back (attenders[i] * 100 / members[i]);

		if (i != 0) {

			old_percentage	= percentage[i-1];
			old_members	= members[i-1];

			delta_percentage.push_back (old_percentage - percentage [i]);
	                delta_members.push_back (old_members - members[i]);

		}
	}


	for (int i = length-1; i >= 0; i--) {
	
		if (i != 0) {

			cpercentages    = base_command + std::to_string (percentage[i]) + "' >> work_files/percentages";
			cmembers        = base_command + std::to_string (members[i]) + "' >> work_files/members";
			cdp             = base_command + std::to_string (delta_percentage[i-1]) + "' >> work_files/dp";
			cdm             = base_command + std::to_string (delta_members[i-1]) + "' >> work_files/dm";
			cspeeches	= base_command + std::to_string (speeches[i]) + "' >> work_files/speeches";

			system (cpercentages.c_str ());
			system (cmembers.c_str ());
			system (cdp.c_str ());
			system (cdm.c_str ());
			system (cspeeches.c_str ());

		} else {

			cpercentages    = base_command + std::to_string (percentage[i]) + "' >> work_files/percentages";
			cmembers        = base_command + std::to_string (members[i]) + "' >> work_files/members";
			cspeeches	= base_command + std::to_string (speeches[i]) + "' >> work_files/speeches";

			system (cpercentages.c_str ());
                        system (cmembers.c_str ());
                        system (cspeeches.c_str ());

		}
	}


	return 0;
}
