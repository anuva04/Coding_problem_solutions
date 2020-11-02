#include <bits/stdc++.h>

using namespace std;
bool sortByVal(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second > b.second);
}
int main()
{
    int t; cin>>t;
    while(t--){
        int num_players, num_months;
        cin>>num_players>>num_months;
        int initial_rating[num_players];
        for(int i=0; i<num_players; i++){
            cin>>initial_rating[i];
        }
        int player_month[num_players][num_months];
        for(int i=0; i<num_players; i++){
            for(int j=0; j<num_months; j++){
                cin>>player_month[i][j];
            }
        }


        int player_month_rating[num_players][num_months+1];
        int player_month_ranking[num_players][num_months+1];


        for(int i=0; i<num_players; i++){
            player_month_rating[i][0] = initial_rating[i];
        }
        for(int i=0; i<num_players; i++){
            for(int j=1; j<=num_months; j++){
                player_month_rating[i][j] = player_month_rating[i][j-1]+player_month[i][j-1];
            }
        }
        for(int i=1; i<=num_months; i++){
            vector<pair<int,int> > vec;
            for(int j=0; j<num_players; j++){
                vec.push_back(make_pair(j,player_month_rating[j][i]));
            }
            sort(vec.begin(),vec.end(),sortByVal);
            int curr_rank=1;
            int k;
            int vecsize=vec.size();
            for(k=0; k<vecsize-1; k++){
                player_month_ranking[vec[k].first][i] = curr_rank;
                if(vec[k+1].second < vec[k].second) curr_rank++;
            }
            if(vec[k].second==vec[k-1].second) player_month_ranking[vec[k].first][i] =curr_rank;
            else player_month_ranking[vec[k].first][i] =curr_rank+1;
        }
        int cnt=0;
        for(int i=0; i<num_players; i++){
            int max_rating = INT_MIN, x;
            int best_rank = INT_MAX, y;
            for(int j=1; j<=num_months; j++){
                if(player_month_rating[i][j]>max_rating){
                    max_rating=player_month_rating[i][j];
                    x=j;
                }
            }
            for(int j=1; j<=num_months; j++){
                if(player_month_ranking[i][j]<best_rank){
                    best_rank=player_month_ranking[i][j];
                    y=j;
                }
            }
            if(x==y) cnt++;
        }

        cout << "rating " <<endl;
        for(int i=0; i<num_players; i++){
            for(int j=0; j<=num_months; j++){
                cout<<player_month_rating[i][j] << " ";
            }
            cout<<endl;
        }
        cout<< "*************************" <<endl;
        cout << "ranking " <<endl;
        for(int i=0; i<num_players; i++){
            for(int j=0; j<=num_months; j++){
                cout<<player_month_ranking[i][j] << " ";
            }
            cout<<endl;
        }
        cout<< "*************************" <<endl;
        cout<<cnt<<endl;
    }
    return 0;
}
