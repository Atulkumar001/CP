 void sol() {
    // when its a hacking contest please use map instead of unordered map
      ll n,k,q;
      cin>>n>>k>>q;
     ll i,j;
     vector<ll>a(1e6+20,0);
     for(i=0;i<n;i++){
        ll l,r;
        cin>>l>>r;
        a[l-1]++;
        a[r]--;
        
     }
     vector<ll>psum(1e6+20,0);
     psum[0] = a[0];
     for(i=1;i<1e6;i++){
        psum[i] =psum[i-1]+a[i];
    }
    for(i=0;i<1e6;i++){
        if(psum[i]>=k){
            psum[i]=1;
        }
        else{
            psum[i] =0;
        }
    }
    vector<ll>psumm(1e6+20,0);
    psumm[0] = psum[0];

    for(i=1;i<1e6;i++){
        psumm[i] = psumm[i-1]+psum[i];
    }
    for(i=0;i<q;i++){
        ll l,r;
        cin>>l>>r;
        if(l==1){
            ll ans = psumm[r-1];
            cout<<ans<<endl;
        }
        else{
            ll ans = psumm[r-1]-psumm[l-2];
            cout<<ans<<endl;
        }
    }
   



    
   }
    
