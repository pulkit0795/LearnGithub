#include<bits/stdc++.h>
using namespace std;
/*
In a particular social network friends are automatically allocated to
users by the system and users cannot add friends of their choice on their own.
There are currently N users on the social network, labeled from 2 to N + 1.
For every i-th user (where i ranges from 2 to N + 1),
the system allocated all the users labeled with multiples of i as the user's friends (if possible).
One day, all users of the social network come together for a meeting and form groups such that
each person in a group is a direct friend or a friend of friend of every other person of that group.
Example: input: 10
Output: 3
Explanation:
Three groups will be formed:{2, 3, 4, 5, 6, 8, 9, 10}, {7} and {11}
approach is union and find
*/
class UnionFindSet{
	private:
		int count;
		vector<int> parent;
	public:
		UnionFindSet(int n){
			count=n;
			parent=vector<int>(n+2);
			for(int i=0;i<parent.size();i++)
				parent[i]=i;
		}
		int find(int a){
			if(a==parent[a])
				return a;
			return parent[a]=find(parent[a]);
		}
		void Union(int a,int b){
			int pa=find(a);
			int pb=find(b);
			if(pa==pb)return;
			if(pa>pb){
            parent[pb]=pa;
			}else{
			parent[pa]=pb;
			}
			count--;
		}
		int numberConnected(){
			return count;}
};

int main() {
    int n;
    cin>>n;
    UnionFindSet U(n+1);
    for(int i=2;i<=n+1;i++){
        for(int j=2;j*i<=n+1;j++)
            U.Union(i,j*i);
    }
    cout<<U.numberConnected()-1;
    return 0;
}
