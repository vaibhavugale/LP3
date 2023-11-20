// #include<iostream>

// using namespace std;
// struct Item {
// 	int profit, weight;
// 	Item(int profit, int weight)
// 	{
// 		this->profit = profit;
// 		this->weight = weight;
// 	}
// };
// static bool cmp(struct Item a, struct Item b)
// {
// 	double r1 = (double)a.profit / (double)a.weight;
// 	double r2 = (double)b.profit / (double)b.weight;
// 	return r1 > r2;
// }

// double fractionalKnapsack(int W, struct Item arr[], int N)
// {
// 	sort(arr, arr + N, cmp);

// 	double finalvalue = 0.0;
// 	for (int i = 0; i < N; i++) {
// 		if (arr[i].weight <= W) {
// 			W -= arr[i].weight;
// 			finalvalue += arr[i].profit;
// 		}
// 		else {
// 			finalvalue
// 				+= arr[i].profit
// 				* ((double)W / (double)arr[i].weight);
// 			break;
// 		}
// 	}

// 	return finalvalue;
// }

// int main()
// {
// 	int W = 50;
// 	Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
// 	int N = sizeof(arr) / sizeof(arr[0]);

// 	cout << fractionalKnapsack(W, arr, N);
// 	return 0;
// }

#include<iostream>

using namespace std;

class node{
public:
int weight;
int profit;
  node(int weight, int profit){
	this->weight = weight;
	this->profit = profit;
  }
};

static bool cmp(node i1, node i2){
     double item1 = (double)i1.profit/(double)i1.weight;
	 double item2 = (double)i2.profit/(double)i2.weight;

	 return item1>item2;
};

double kf(vector< node > arr,int size,int W){
	sort(arr.begin(),arr.end(),cmp);
	double totalProfit = 0;
	for(int i=0;i<size;i++){
		if(W >=arr[i].weight){
			W=W-arr[i].weight;
			totalProfit+=arr[i].profit;

		}else{
			totalProfit += arr[i].profit* (double)W/arr[i].weight;
			break;			
			}
	}

	return totalProfit;
}


int main(){
    node tem1 =  node(10,60);
	node tem2 =  node(20,100);
	node tem3 =  node(30,120);

	vector<node> temp;
	temp.push_back(tem1);
	temp.push_back(tem2);
	temp.push_back(tem3);

	cout<< kf(temp,temp.size(),50)<<" ";
	return 0;
}





