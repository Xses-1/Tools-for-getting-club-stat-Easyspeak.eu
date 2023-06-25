#include <bits/stdc++.h>
  
struct things {

	std::string link;

	std::vector<std::string> linkings;

	int line_counter;
} t;

int main () {

	std::ifstream meetings_links ("meetings_links");

	t.line_counter = 0;

	while (std::getline (meetings_links, t.link)) {

                t.line_counter++;
		t.linkings.push_back(t.link);
        }

	meetings_links.clear ();
        meetings_links.seekg (0, std::ios::beg);

	for (int i = t.line_counter-1; i >= 0; i--) {

		std::cout << "https://tmclub.eu/" << t.linkings[i] << std::endl;
	}

	meetings_links.close ();

	
        return 0;

}
