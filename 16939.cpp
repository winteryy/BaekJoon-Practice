#include <iostream>
#include <vector>

using namespace std;

class Cube {
public:
    vector<int> faces;

    Cube() {
        faces = vector<int>(24);
    }

    void insertFaces() {
        for(int i=0; i<24; i++) {
            cin >> faces[i];
        }
    }

    bool checkRotate() {

        if(faces[0]==faces[2]&&faces[0]==faces[22]&&faces[0]==faces[20]
        &&faces[4]==faces[6]&&faces[4]==faces[1]&&faces[4]==faces[3]
        &&faces[8]==faces[10]&&faces[8]==faces[5]&&faces[8]&&faces[7]
        &&faces[23]==faces[21]&&faces[23]==faces[9]&&faces[23]==faces[11]
        &&faces[12]==faces[13]&&faces[12]==faces[14]&&faces[12]==faces[15]
        &&faces[16]==faces[17]&&faces[16]==faces[18]&&faces[16]==faces[19]) {
            return true;
        }
        if(faces[0]==faces[2]&&faces[0]==faces[5]&&faces[0]==faces[7]
        &&faces[4]==faces[6]&&faces[4]==faces[9]&&faces[4]==faces[11]
        &&faces[8]==faces[10]&&faces[8]==faces[22]&&faces[8]&&faces[20]
        &&faces[23]==faces[21]&&faces[23]==faces[1]&&faces[23]==faces[3]
        &&faces[12]==faces[13]&&faces[12]==faces[14]&&faces[12]==faces[15]
        &&faces[16]==faces[17]&&faces[16]==faces[18]&&faces[16]==faces[19]) {
            return true;
        }
        if(faces[4]==faces[5]&&faces[4]==faces[18]&&faces[4]==faces[19]
        &&faces[16]==faces[17]&&faces[16]==faces[22]&&faces[16]==faces[23]
        &&faces[20]==faces[21]&&faces[20]==faces[14]&&faces[20]&&faces[15]
        &&faces[12]==faces[13]&&faces[12]==faces[6]&&faces[12]==faces[7]
        &&faces[0]==faces[1]&&faces[0]==faces[2]&&faces[0]==faces[3]
        &&faces[8]==faces[9]&&faces[8]==faces[10]&&faces[8]==faces[11]) {
            return true;
        }
        if(faces[4]==faces[5]&&faces[4]==faces[14]&&faces[4]==faces[15]
        &&faces[16]==faces[17]&&faces[16]==faces[6]&&faces[16]==faces[7]
        &&faces[20]==faces[21]&&faces[20]==faces[18]&&faces[20]&&faces[19]
        &&faces[12]==faces[13]&&faces[12]==faces[22]&&faces[12]==faces[23]
        &&faces[0]==faces[1]&&faces[0]==faces[2]&&faces[0]==faces[3]
        &&faces[8]==faces[9]&&faces[8]==faces[10]&&faces[8]==faces[11]) {
            return true;
        }
        if(faces[0]==faces[1]&&faces[0]==faces[16]&&faces[0]==faces[18]
        &&faces[17]==faces[19]&&faces[17]==faces[9]&&faces[17]==faces[8]
        &&faces[11]==faces[10]&&faces[11]==faces[15]&&faces[11]&&faces[13]
        &&faces[14]==faces[12]&&faces[14]==faces[2]&&faces[14]==faces[3]
        &&faces[4]==faces[5]&&faces[4]==faces[6]&&faces[4]==faces[7]
        &&faces[20]==faces[21]&&faces[20]==faces[22]&&faces[20]==faces[23]) {
            return true;
        }
        if(faces[0]==faces[1]&&faces[0]==faces[15]&&faces[0]==faces[13]
        &&faces[17]==faces[19]&&faces[17]==faces[2]&&faces[17]==faces[3]
        &&faces[11]==faces[10]&&faces[11]==faces[16]&&faces[11]&&faces[18]
        &&faces[14]==faces[12]&&faces[14]==faces[9]&&faces[14]==faces[8]
        &&faces[4]==faces[5]&&faces[4]==faces[6]&&faces[4]==faces[7]
        &&faces[20]==faces[21]&&faces[20]==faces[22]&&faces[20]==faces[23]) {
            return true;
        }    

        return false;   
    }
};

int main() {
    Cube cube = Cube();

    cube.insertFaces();

    cout << cube.checkRotate();
}