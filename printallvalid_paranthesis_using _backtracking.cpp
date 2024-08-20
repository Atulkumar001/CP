// learn backtracking
// question is to print all valid parnathesis of size n



Level
We need to keep track of current length, the total length, and the number of opening parentheses.

Choice
We have two choices: either add an opening parenthesis or a closing parenthesis. However, you have to make sure that the resulting sequence is still balanced. If you are adding a opening bracket increase the opening bracket count by 1, else for closing bracket decrease the opening bracket count by 1.

Check
Check if after adding a bracket the sequence is still valid or not.

Transition(move) LCCM 
After taking an opening bracket call the DFS with the updated sequence, length, and number of opening parentheses. If the length of the sequence is n, then print the sequence. Otherwise, backtrack.







    vector<vector<string>>v;
    ll i,j;
    ll n;
    vector<string>temp;
    ll co =0;
    ll cc =0;
    void pn(){
        sort(v.begin(),v.end());
        int i,j;
        for(i=0;i<v.size();i++){
            for(j=0;j<v[i].size();j++){
                cout<<v[i][j];
            }
            cout<<"\n";
        }
    }
    bool check(int co, int cc){
      // check will be that depth should be less than or equal to n/2
        if(co-cc>n/2 || cc>co){
            return 0;
        }
        else{
            return 1;
        }
        // basically depth is abs difference between co - cc  also cc should never be
        // greater than co
    }
    void rec(int level){
        // here we have to call recursively starting from first index , we got two choices 
        // one to open bracket and other one is closed bracket

        if(level==n){
            if(check(co,cc)){
                 v.push_back(temp);
               //  temp.clear();
// clear isiliye nhi krna hota h kyuki backtracking apna state wapas se restore kr lete h , pop back wali line dekho bhai , isiliye to ye memory efficient hai
            return;
            }
             //temp.clear();
        }
   // here we either push the opening bracket and push it
            // or we will push the closing bracket and push it
        if(co<n/2){
              temp.push_back("(");
            co++;
            rec(level+1);
            temp.pop_back();
            co--;
        }
        if(co>cc){

            temp.push_back(")");
            cc++;
            rec(level+1);
            temp.pop_back();
            cc--;
        }
           
        
       
        
        return;
    }





      void sol() {
    // when its a hacking contest please use map instead of unordered map
        
       
        cin>>n;
        rec(0);
        pn();

   }
// vivek op in the chat
