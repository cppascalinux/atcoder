#include<bits/stdc++.h>using namespace std;const char *sr[5]={"dragon","ninja","iceman","lion","wolf"};const char *sp[3]={"sword","bomb","arrow"};const char *sc[2]={"red","blue"};const int od[2][5]={{2,3,4,1,0},{3,0,1,2,4}};int h0[5],f0[5];int m0,n0,r0,k0,t0,clk;char buf[100009];int sk[30],flg[30],ade[30];int sme[2],tae[2],enm[2];vector<int> rwd[2];struct warrior;struct msg;int fight(warrior &w1,warrior &w2,int rl);struct msg{int v;string sr;msg(int tm,int ps,int tp,int cl,string sr):v(tm*704+ps*32+tp*2+cl),sr(sr){}bool operator<(const msg &y)const{return v<y.v;}void print(){printf("%s",sr.c_str());}};vector<msg> ans;struct warrior{int cl,tp,id,hl,fc,ps;int sw,bb,ar;double mr;int ly;warrior(int cl,int tp,int id,int sm):cl(cl),tp(tp),id(id),hl(0),fc(0),ps(0),sw(0),bb(0),ar(0),mr(0),ly(0){ps=cl?n0+1:0;hl=h0[tp],fc=f0[tp];if(tp<=2){int v=id%3;if(v==0||(tp==1&&v==2))sw=fc*2/10;if(v==1||(tp==1&&v==0))bb=1;if(v==2||(tp==1&&v==1))ar=3;}if(tp==0)mr=(double)sm/hl;if(tp==3)ly=sm;int l=sprintf(buf,"%03d:00 %s %s %d born\n",clk,sc[cl],sr[tp],id);if(tp==0)sprintf(buf+l,"Its morale is %.2lf\n",mr);else if(tp==3)sprintf(buf+l,"Its loyalty is %d\n",ly);ans.emplace_back(clk*100,ps,1,cl,buf);}void flee(){if(tp==3&&ly<=0&&(cl?ps>=1:ps<=n0)){sprintf(buf,"%03d:05 %s %s %d ran away\n",clk,sc[cl],sr[tp],id);ans.emplace_back(clk*100+5,ps,2,cl,buf);hl=0;}}void walk(){if(ps==(cl?0:n0+1))return;ps+=cl?-1:1;if(tp==2){int l=cl?n0+1-ps:ps;if(l%2==0)fc+=20,hl=hl>9?hl-9:1;}if(ps>=1&&ps<=n0){sprintf(buf,"%03d:10 %s %s %d marched to city %d with %d elements and force %d\n",clk,sc[cl],sr[tp],id,ps,hl,fc);ans.emplace_back(clk*100+10,ps,3,cl,buf);}else{sprintf(buf,"%03d:10 %s %s %d reached %s headquarter with %d elements and force %d\n",clk,sc[cl],sr[tp],id,sc[cl^1],hl,fc);ans.emplace_back(clk*100+10,ps,12,cl,buf);if(++enm[cl^1]>=2){sprintf(buf,"%03d:10 %s headquarter was taken\n",clk,sc[cl^1]);ans.emplace_back(clk*100+10,ps,13,cl,buf);}}}void shoot(warrior &y){if(ar>0){ar--;int l=sprintf(buf,"%03d:35 %s %s %d shot",clk,sc[cl],sr[tp],id);if((y.hl-=r0)<=0)l+=sprintf(buf+l," and killed %s %s %d",sc[y.cl],sr[y.tp],y.id);sprintf(buf+l,"\n");ans.emplace_back(clk*100+35,ps,4,cl,buf);}}void bomb(warrior &y){if(hl>0&&y.hl>0&&bb&&!fight(*this,y,0)){hl=y.hl=0;sprintf(buf,"%03d:38 %s %s %d used a bomb and killed %s %s %d\n",clk,sc[cl],sr[tp],id,sc[y.cl],sr[y.tp],y.id);ans.emplace_back(clk*100+38,ps,5,cl,buf);}}void report(){int l=sprintf(buf,"%03d:55 %s %s %d has ",clk,sc[cl],sr[tp],id);int fg=0;if(ar>0)l+=sprintf(buf+l,"%sarrow(%d)",fg?",":"",ar),fg=1;if(bb>0)l+=sprintf(buf+l,"%sbomb",fg?",":""),fg=1;if(sw>0)l+=sprintf(buf+l,"%ssword(%d)",fg?",":"",sw),fg=1;if(!fg)l+=sprintf(buf+l,"no weapon");sprintf(buf+l,"\n");ans.emplace_back(clk*100+55,cl,0,ps,buf);}};void modify(warrior &x,warrior &y,int yhl){if(x.hl<=0)return;if(x.tp==0){if(y.hl<=0)x.mr+=0.2;else x.mr-=0.2;}else if(x.tp==3){if(y.hl>0)x.ly-=k0;}else if(x.tp==4&&y.hl<=0){if(x.sw<=0)x.sw=y.sw;if(x.ar<=0)x.ar=y.ar;if(x.bb<=0)x.bb=y.bb;}if(y.hl<=0){if(y.tp==3)x.hl+=max(yhl,0);rwd[x.cl].push_back(x.id);if(ade[x.ps]){sprintf(buf,"%03d:40 %s %s %d earned %d elements for his headquarter\n",clk,sc[x.cl],sr[x.tp],x.id,ade[x.ps]);ans.emplace_back(clk*100+40,x.ps,10,x.cl,buf);tae[x.cl]+=ade[x.ps],ade[x.ps]=0;}if(x.cl)sk[x.ps]=max(sk[x.ps],0);else sk[x.ps]=min(sk[x.ps],0);sk[x.ps]+=x.cl?1:-1;if(abs(sk[x.ps])>=2&&flg[x.ps]!=x.cl){flg[x.ps]=x.cl;sprintf(buf,"%03d:40 %s flag raised in city %d\n",clk,sc[x.cl],x.ps);ans.emplace_back(clk*100+40,x.ps,11,x.cl,buf);}}else sk[x.ps]=0;}int fight(warrior &w1,warrior &w2,int rl){int flp=0;warrior x(w1),y(w2);if((flg[x.ps]==1||(flg[x.ps]==-1&&x.ps%2==0))^x.cl)swap(x,y),flp=1;int xhl=x.hl,yhl=y.hl;if(x.hl<=0&&y.hl<=0)return 0;if(x.hl>0&&y.hl>0){sprintf(buf,"%03d:40 %s %s %d attacked %s %s %d in city %d with %d elements and force %d\n",clk,sc[x.cl],sr[x.tp],x.id,sc[y.cl],sr[y.tp],y.id,x.ps,x.hl,x.fc);if(rl)ans.emplace_back(clk*100+40,x.ps,6,x.cl,buf);y.hl-=x.sw+x.fc;x.sw=x.sw*8/10;if(y.hl>0&&y.tp!=1){sprintf(buf,"%03d:40 %s %s %d fought back against %s %s %d in city %d\n",clk,sc[y.cl],sr[y.tp],y.id,sc[x.cl],sr[x.tp],x.id,x.ps);if(rl)ans.emplace_back(clk*100+40,x.ps,7,y.cl,buf);x.hl-=y.sw+y.fc/2;y.sw=y.sw*8/10;}if(x.hl<=0||y.hl<=0){warrior d=x.hl<=0?x:y;sprintf(buf,"%03d:40 %s %s %d was killed in city %d\n",clk,sc[d.cl],sr[d.tp],d.id,d.ps);if(rl)ans.emplace_back(clk*100+40,d.ps,8,d.cl,buf);}}if(rl){modify(x,y,yhl);modify(y,x,xhl);if(x.tp==0&&x.hl>0&&x.mr>0.8){sprintf(buf,"%03d:40 %s dragon %d yelled in city %d\n",clk,sc[x.cl],x.id,x.ps);ans.emplace_back(clk*100+40,x.ps,9,x.cl,buf);}}if(flp)swap(x,y);if(rl)w1=x,w2=y;return x.hl<=0?0:1;}void clean(vector<warrior> &v){vector<warrior> tmp;for(auto x:v)if(x.hl>0)tmp.push_back(x);tmp.swap(v);}bool cmp1(const warrior &a,const warrior &b){return a.ps<b.ps;}bool cmp2(const warrior &a,const warrior &b){return a.ps>b.ps;}void solve(){memset(sk,0,sizeof(sk));memset(flg,-1,sizeof(flg));memset(ade,0,sizeof(ade));for(int i:{0,1})rwd[i].clear(),tae[i]=enm[i]=0,sme[i]=m0;ans.clear();vector<warrior> wr[2];int id[2]={0,0},stp=0;for(clk=0;t0>=0;clk++,t0-=60){if(t0>=0){for(int i:{0,1}){int v=od[i][id[i]%5];if(sme[i]>=h0[v]){sme[i]-=h0[v];wr[i].emplace_back(i,v,++id[i],sme[i]);}}}if(t0>=5){for(int i:{0,1}){for(auto &x:wr[i])x.flee();clean(wr[i]);}}if(t0>=10){for(int i:{0,1})for(auto &x:wr[i])x.walk();for(int i:{0,1})if(enm[i]>=2)stp=1;if(stp)break;}if(t0>=20)for(int i=1;i<=n0;i++)ade[i]+=10;if(t0>=30){for(int i:{0,1})for(auto x:wr[i]){int fg=0;for(auto y:wr[i^1])if(y.ps==x.ps)fg=1;if(!fg&&ade[x.ps]){sprintf(buf,"%03d:30 %s %s %d earned %d elements for his headquarter\n",clk,sc[x.cl],sr[x.tp],x.id,ade[x.ps]);ans.emplace_back(clk*100+30,x.ps,10,x.cl,buf);sme[i]+=ade[x.ps],ade[x.ps]=0;}}}if(t0>=35){for(int i:{0,1})for(auto &x:wr[i])for(auto &y:wr[i^1])if(y.ps-x.ps==(i?-1:1))x.shoot(y);}if(t0>=38){for(auto &x:wr[0])for(auto &y:wr[1])if(x.ps==y.ps)x.bomb(y),y.bomb(x);}if(t0>=40){for(auto &x:wr[0])for(auto &y:wr[1])if(x.ps==y.ps)fight(x,y,1);for(int i:{0,1}){sort(rwd[i].begin(),rwd[i].end());if(i)sort(wr[i].begin(),wr[i].end(),cmp1);else sort(wr[i].begin(),wr[i].end(),cmp2);for(auto &x:wr[i])if(sme[i]>=8){auto it=lower_bound(rwd[i].begin(),rwd[i].end(),x.id);if(it<rwd[i].end()&&*it==x.id)x.hl+=8,sme[i]-=8;}rwd[i].clear();sme[i]+=tae[i],tae[i]=0;clean(wr[i]);}}if(t0>=50)for(int i:{0,1}){sprintf(buf,"%03d:50 %d elements in %s headquarter\n",clk,sme[i],sc[i]);ans.emplace_back(clk*100+50,0,14,i,buf);}if(t0>=55)for(int i:{0,1})for(auto x:wr[i])x.report();}sort(ans.begin(),ans.end());for(auto x:ans)x.print();}int main(){int tst;scanf("%d",&tst);for(int tt=1;tt<=tst;tt++){printf("Case %d:\n",tt);scanf("%d%d%d%d%d",&m0,&n0,&r0,&k0,&t0);for(int i=0;i<5;i++)scanf("%d",h0+i);for(int i=0;i<5;i++)scanf("%d",f0+i);solve();}return 0;}