#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class SRMRoomAssignmentPhase {

public:
	int countCompetitors(vector <int> ratings, int K) {
		int rat = ratings[0];
		int count = 0;

		for(int i = 1; i < ratings.size(); i++){
			if(ratings[i] > rat) count ++;
		}
		
		return (count / K);
	}
};

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
