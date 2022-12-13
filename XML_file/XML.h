int mark = 0;
stack<char> characters;
//stack<tag> tags;
typedef struct {
    int index;
    string s;
} tag;
stack<tag> errors_miss;
stack<tag> errors_miss1;
stack<tag> errors_wrong_poss;
stack<tag> errors_wrong_poss1;
deque<tag> tags;
deque<tag> temp;
int k = 50;
