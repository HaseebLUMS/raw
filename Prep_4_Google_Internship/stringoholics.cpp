long long gcd(long long a,long long b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int Solution::solve(vector<string> &A) {
    long long aa=1;
    unordered_map<long long,long long> crr;
    for(int h=0;h<A.size();h++){
        long long k=(A[h].length())*2;
        long long kk;
        for(long long j=1;j<((A[h].length())*2);j++){
            if((j*(j+1))%k==0){
                kk=j;
                break;
            }
        }
        long long i=2;
        unordered_map<long long,long long> arr;
        while(i*i<=kk){
            if(kk%i!=0){
                i++;
                continue;
            }
            kk/=i;
            arr[i]++;
        }
        if(kk!=1)
        arr[kk]++;
        for(auto i:arr){
            if(crr[i.first]<i.second)
                crr[i.first]=i.second;
        }
        
    }
    for(auto i:crr){
        for(int j=0;j<i.second;j++)
            aa=(aa*(i.first))%1000000007;
    }
    return aa;
    
}
