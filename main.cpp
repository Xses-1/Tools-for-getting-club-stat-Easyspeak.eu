#include <bits/stdc++.h>
  
struct things {

	std::string link, command0, command1, command2, command3, raw_line, data;
	
	int line_counter;
} t;

int main () {

	int j;

	t.line_counter	= 0;
	t.link		= "";
	t.command1	= "";
	t.command2	= "";
	t.command3	= "";
	t.raw_line	= "";
	t.data		= "";

	std::ifstream meetings_links ("meetings/meetings_links");

	while (std::getline (meetings_links, t.link)) {

		t.line_counter++;
		//t.line_counter = 3;
	}

	t.command0 = "echo " + std::to_string(t.line_counter) + " >> data/meetings_amount";
	system (t.command0.c_str ());

	meetings_links.clear ();
        meetings_links.seekg (0, std::ios::beg);

	for (int i = 0; i < t.line_counter; i++) {

		std::getline (meetings_links, t.link);
		
		t.command1 = "w3m -dump https://tmclub.eu/" + t.link + " | grep '  Member (' >> data/raw_data";
		system (t.command1.c_str ());

		std::cout << "(Task 1 of 2)   " << i + 1 << "/" << t.line_counter << "   (" << (i + 1) * 100 / t.line_counter << "%)" << std::endl;
	}

	std::cout << std::endl;

	meetings_links.clear ();
        meetings_links.seekg (0, std::ios::beg);

	std::ifstream raw_data ("data/raw_data");

	for (int i = 0; i < t.line_counter; i++) {	

		std::getline (raw_data, t.raw_line);

		for (j = 0; t.raw_line[j] != '/' && j != t.raw_line.length (); j++) {};
		
		t.command2 = "echo -n '" + std::to_string (i + 1) + "  ";

		for (int k = -3; k < 3; k++) {

			if (k == 0) {
				k = 1;
			}

			if (t.raw_line[j+k] == '(' || t.raw_line[j+k] == ')') {
				
				t.raw_line[j+k] = ' ';
			}

			t.command2 = t.command2 + t.raw_line[j+k];
		}	
		
		t.command2 = t.command2 + "   ' >> data/club_stats;";
		system (t.command2.c_str ());
		// This is debug output to the terminal
		// std::cout << t.command2 << std::endl << std::endl;


		std::getline (meetings_links, t.link);
		t.command3 = "w3m -dump https://tmclub.eu/" + t.link + " | grep -c ' Speaker' >> data/club_stats;";
		system (t.command3.c_str ());
		// This is debug output to the terminal
		// std::cout << t.command3 << std::endl << std::endl;

		std::cout << "(Task 2 of 2)   " << i + 1 << "/" << t.line_counter << "   (" << (i + 1) * 100 / t.line_counter << "%)" << std::endl;
	}

	meetings_links.close ();
	raw_data.close ();

	
        return 0;

}
