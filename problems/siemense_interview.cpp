#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'groupTransactions' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY transactions as parameter.
 */

bool order_comp(const pair<string,int> &a , const pair<string, int> &b){
    
    if(a.second > b.second){
        return true;
    }else if (b.second > a.second){
        return false;
    }else{
        return a.first < b.first;
    }
    
}

vector<string> groupTransactions(vector<string> transactions) {

    map<string,int> counter;
    vector<pair<string,int>> mvec;
    vector<string> final_vec;
    for(int i = 0 ; i < transactions.size(); i ++){
        counter[transactions[i]]++;
    }
    
    map<string,int>::iterator it;
    
    for(it = counter.begin(); it!=counter.end() ; it++){
        mvec.push_back({it->first , it->second});
    }
    
    sort(mvec.begin() , mvec.end() , order_comp);
    
    for(int i = 0 ; i < mvec.size(); i++){
        string s = mvec[i].first + to_string(mvec[i].second);
        final_vec.push_back(s);
    }
    return final_vec;

}

int main(){

    printf("%s", 5 +"asdadqweqwe");
}



#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'strokesRequired' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY picture as parameter.
 */

int strokesRequired(vector<string> picture) {
    int w = picture[0].length();
    int h = picture.size();
    int ans = 0;
    cout<<w<<" "<<h<<endl;
    vector<vector<bool>> vis(h,vector<bool>( w, false));
    stack<pair<int,int>> tovis;
    for(int i = 0 ; i<h ; i ++){
        for(int j = 0 ; j < w ;j++){
            if(!vis[i][j]){
                char cur_color = picture[i][j];
                tovis.push({i,j});
                ans++;
                while(!tovis.empty()){
                    int cur_i = tovis.top().first;
                    int cur_j = tovis.top().second;
                    tovis.pop();
                    cout<<ans<<" "<<cur_i<<" "<<cur_j<<endl;
                    vis[cur_i][cur_j] = 1;
                    if(cur_i > 0 && !vis[cur_i-1][cur_j] && picture[cur_i-1][cur_j] == cur_color){
                        tovis.push({cur_i-1,cur_j});
                        vis[cur_i-1][cur_j] = 1;
                    }
                    if(cur_i <h-1 && !vis[cur_i+1][cur_j] && picture[cur_i+1][cur_j] == cur_color){
                        tovis.push({cur_i+1,cur_j});
                        vis[cur_i+1][cur_j] = 1;
                    }
                    if(cur_j >0 && !vis[cur_i][cur_j-1] && picture[cur_i][cur_j-1] == cur_color){
                        tovis.push({cur_i,cur_j-1});
                        vis[cur_i][cur_j-1] = 1;
                    }
                    if(cur_j <w-1 && !vis[cur_i][cur_j+1] && picture[cur_i][cur_j+1] == cur_color){
                        tovis.push({cur_i,cur_j+1});
                        vis[cur_i][cur_j+1] = 1;
                    }
                    
                }
                
            }
        }
        
    }
    
    return ans;
    
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string picture_count_temp;
    getline(cin, picture_count_temp);

    int picture_count = stoi(ltrim(rtrim(picture_count_temp)));

    vector<string> picture(picture_count);

    for (int i = 0; i < picture_count; i++) {
        string picture_item;
        getline(cin, picture_item);

        picture[i] = picture_item;
    }

    int result = strokesRequired(picture);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}



char a[] = ""
cout<<sizeof(a);


class String{
    public:
    explicit String (char c , int n =1){}
    String(const char *p){}
    private:
    void operator=(const char*){}
};

String x = "aaa";



class ai{

    public:
    int a;
    int b;
    ai(int i ):a(i) , b(a+1){};
};
ai s(5);
    cout<<s.a<<s.b;





// will this compile
    int *x , *y;
    x= &(y);
    y= &(x);




// pointer to pointer of array of int
    int **a[5];



    int x = 4 , *y;
    y = &x;
    (*y)++;
    cout<<*y;





    int a[4][2] = {0};

    cout<<sizeof(a);





    int x[] = {1,2,3,6,5};
int *ptr , y;
ptr = x+4;
y= ptr-x;
cout<<y;



int x = 0;
for(x =1 ; x < 4 ; x++);
printf("%d",x);
    


cpp operators that cannt be overloaded :
::	.*	.	?:




doubly linked list  : 1 )c++ linear or circular ,2)  same size as nomrmal lonked list , 3 ) must have header



malloc , sizeof , realloc // *ptr , realocate to array of 10




question on template


//coding:

1)
givenn picture  vector<string> picture , each row is row in that piture and each character is color ,what is minimum number of strockes to paint all the pic strock can move left , rifht up and down if same color only
//use stack and mark vis



2)
given string vector , conut each string showed how many times and sort it through the highest count then ascending through name if same count
// solved using map then vector comparator sort