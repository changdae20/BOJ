#include <bits/stdc++.h>
std::vector<int> v{0,1,906150256,906150293,906150294,906150307,906150310,906150313,906150314,906151515,906151516,906151575,906154582,906154585,906154604,906154605,906154608,906154757,906154762,906154763,906154768,906154769,906154788,906154789,906154790,906154791,906154792,906154793,906154824,906154825,906154828,906154829,906154836,906154837,906154856,906154857,906154864,906154881,906154884,906154885,906154886,906154887,906154888,906154889,906154890,906154891,906154892,906154893,906154894,906154907,906154908,906154911,906154914,906154927,906154946,906154949,906180358,906180361,906180362,906180363,906180364,906180365,906180366,906180369,906180370,906180373,906180374,906180375,906180390,906180517,906180518,906180519,906180524,906180533,906180536,906180553,906180554,906192697,906192846,906192865,906192866,906192903,906192904,906192905,906192906,906192965,906192970,906192971,906192978,906192983,906192984,906193227,906193228,906193233,906193244,906193245,906193246,906193247,906193302,906193303,906193418,906193419,906193464,906193465,906193474,906193475,906193476,906193477,906194930,906194931,906194932,906194945,906194948,906194949,906194950,906194967,906194978,906194979,906195098,906195099,906195108,906195149,906195150,906195151,906195296,906195297,906195298,906195985,906195988,906195989,906196008,906196009,906196010,906196013,906196014,906196015,906196044,906196051,906196052,906196055,906196056,906196071,906196076,906196079,906196080,906196081,906196082,906196091,906196098,906208711,906208712,906208713,906208730,906208731,906209040,906209063,906209066,906209067,906209068,906209069,906209070,906209223,906209226,906209227,906209232,906209235,906209236,906209237,906209240,906209241,906209242,906209271,906209282,906209283,906209284,906477701,906477734,906477811,906477866,906477867,906477868,906477869,906477870,906477899,906477900,906477901,906477902,906477905,906477928,906477931,906477932,906477933,906477934,906477935,906477936,906486639,906486804,906486805,906486806,906486807,906486816,906486817,906486818,906486819,906486820,906486831,906486842,906486853,906486854,906486855,906486908,906486913,906486916,906486973,906486974,906487001,906487004,906487063,906487064,906487065,906487068,906487069,906487070,906487071,906487072,906487077,906487084,906487085,906487086,906487101,906487184,906487185,906487186,906487189,906487190,906487191,906487192,906487193,906487194,906487203,906487204,906487205,906487258,906487259,906487260,906487261,906487262,906487263,906487270,906487287,906487932,906487933,906487936,906487937,906487948,906487973,906487974,906487993,906487994,906488001,906488002,906488003,906488006,906488007,906488008,906488009,906488022,906488025,906488026,906488065,906488066,906488067,906488076,906488079,1000000000};
int main(){
    std::cin.tie( NULL );
    std::ios::sync_with_stdio( false );
    std::cout.tie( NULL );
    int T,n;
    std::cin >> T;
    while(T--){
        std::cin >> n;
        std::cout<<(std::distance(v.begin(),std::lower_bound(v.begin(),v.end(),n))%2 ?"E":"O")<<'\n';
    }
    return 0;
}