#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void multiply(double arr1[3][2], double arr2[2][1], double arr3[3][1]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 1; j++){
            arr3[i][j] = 0;
            for(int k = 0; k < 2; k++){
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

int main() {
    // int N=3;
    cout<<"Enter radius of wheel: ";
    double r;
    cin>>r;
    cout<<"Enter distance between wheels: ";
    double ws;
    cin>>ws;
    cout<<"Enter theta: ";
    double theta;
    cin>>theta;
    cout<<"Enter velocity of right wheel: ";
    double vr;
    cin>>vr;
    cout<<"Enter velocity of left wheel: ";
    double vl;
    cin>>vl;
    // cin>>N;
    

    double arr1[3][2] = {
        {r*cos(theta)/2,-r*sin(theta)/2},
        {r*sin(theta)/2,r*cos(theta)/2},
        {r/ws,-(r/ws)}
    };
    
    double arr2[2][1] = {
        {vr},
        {vl}
    };
    
    double arr3[3][1];
    multiply(arr1,arr2,arr3);
    
    cout<<"Multiplication of 2 matrix:"<<endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 1; j++){
            cout<<arr3[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     // shape of m1 matrix
//     int m;
//     int n;
    
//     // shape of m2 matrix
//     int p;
//     int q;
    
//     cin>>m>>n>>p>>q;
    
    
//     if(n != p){
//         cout<<"Matrix multiplication can't be performed due to invalid shape!"<<endl;
//     }
    
//     // Init values in m1.
//     int m1[m][n];
//     for(int i = 0; i < m; i++){
//         for(int j = 0; j < n; j++){
//             cin>>m1[i][j];
//         }
//     }
//     // Init values in m2.
//     int m2[p][q];
//     for(int i = 0; i < p; i++){
//         for(int j = 0; j < q; j++){
//             cin>>m2[i][j];
//         }
//     }
    
//     // create our resultant matrix m3 with shape m,q
//     int m3[m][q];
//      for(int i = 0; i < m; i++){
//         for(int j = 0; j < q; j++){
//             m3[i][j] = 0;
//         }
//     }
//     //  Finding the product of 2 matrices and storing it in a new matrix.
//     for(int i = 0; i < m; i++){
//         for(int j = 0; j < q; j++){
//             for(int k = 0; k < n;k++){
//                 m3[i][j] += m1[i][k]*m2[k][j];
//             }
//         }
//     }
    
//     // Printing the resultant matrix.
//     for(int i = 0; i<m;i++){
//         for(int j = 0; j <q; j++){
//             cout<<m3[i][j]<<" ";
//         }
//         cout<<endl;
//     }
    
//     return 0;
// }

//matrix A = [[cos theta -sin theta x],
            // [sin theta cos theta y],
            // [0 0 1]]

// matrix B= [[Vx],
//            [Vy],
//             [W]]

// Vx=r/2 * alpha dot right* cos theta + r/2*alpha dot left  *sin theta
// Vy=r/2 * alpha dot right*sin theta + r/2*alpha dot left  *cos theta
// W = r/ws *alpha dot right - r/ws *alpha dot left  

// velocity in x,y,theta

// velocity in global reference frame=matrix A*matrix B

//output x dot ,  y dot, theta dot 

//IN CASE OF ENCODERS

//[[X],     D*cos(theta)    [delta x]
// [Y], +   D*sin(theta)    [delta y]
// [theta]]     delta(theta)   [delta theta]
    // == global position of differential robot     predict of robot position 
    // localization of robot by prediction model 

// D = (dr+dl)/2

// dr=  (S(r @ t1)- S(r @ t0)/Q) * (2*pi*r)
//  dl=  (S(l @ t1)- S(l @ t0)/Q) * (2*pi*r)

// time is 1 sec
// Q = 1000 ticks one rotation of wheel 



