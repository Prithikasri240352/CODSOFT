//R.Prithikasri CODSOFT Task5: Image Processing Tool

#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;
void displayImage(const vector<vector<int> >& image) { 
    for (size_t i = 0; i < image.size(); ++i) 
    {
     for (size_t j = 0; j < image[i].size(); ++j)
      {
  cout << image[i][j] << " "; } cout << endl;
          } 
     }
 vector<vector<int> > invertImage(const vector<vector<int> >& image) { vector<vector<int> > invertedImage = image; 
 for (size_t i = 0; i < invertedImage.size(); ++i) 
 {
 for (size_t j = 0; j < invertedImage[i].size(); ++j)
      { 
      invertedImage[i][j] = 255 - invertedImage[i][j];
     } 
        } 
    return invertedImage;
     }
vector<vector<int> > adjustColor(const vector<vector<int> >& image, double alpha, int beta){
    vector<vector<int> > adjustedImage=image;
    for(size_t i=0;i<adjustedImage.size();++i)
    {
        for(size_t j=0;j<adjustedImage[i].size();++j)
        {
            adjustedImage[i][j]=min(max(int(image[i][j]*alpha+ beta),0),255);
        }

    }
    return adjustedImage;
}
vector<vector<int> > cropImage(const vector<vector<int> >& image,int startX, int startY, int width, int height){
    vector<vector<int> >croppedImage(height, vector<int>(width));
    for(int i=0; i < height;++i)
    {
        for(int j=0;j < width;++j)
        {
croppedImage[i][j]=image[startY + i][startX + j];
        }
    }
    return croppedImage;
}
void saveImage(const vector<vector<int> >& image, const string& filename){
    ofstream outputFile(filename.c_str());
    outputFile<<image.size()<<" "<<image[0].size()<<endl;
    for(size_t i=0;i<image.size();++i)
    {
        for(size_t j=0;j<image[i].size(); ++j)
        {
            outputFile<<image[i][j]<<" ";
        }
        outputFile<<endl;
    }
    outputFile.close();
}
int main()
{
    string fileName;
    cout<<"Enter the image(e,g, image.txt): ";
    cin>>fileName;
    ifstream inputFile(fileName.c_str());
    if(!inputFile)
    {
        cerr<<"Error opening file!"<<endl;
        return 1;
    }
    int rows, cols;
    inputFile>>rows>>cols;
    vector<vector<int> > image(rows, vector<int>(cols));
    for(int i=0;i<rows;++i){
for(int j=0;j<cols;++j){
    inputFile>>image[i][j];
}
    }
    inputFile.close();
    int choice;
    do{
        cout<<"\nImage Processing Tool"<<endl;
        cout<<"1. Display Image"<<endl;
        cout<<"2. Invert Image"<<endl;
        cout<<"3. Adjust Color"<<endl;
        cout<<"4. Crop Image"<<endl;
        cout<<"5. Save Image"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            displayImage(image);
            break;
            case 2:
            image=invertImage(image);
            cout<<"Image inverted successfully."<<endl;
            break;
            case 3:{
            double alpha;
            int beta;
            cout<<"Enter alpha(contrast) value: ";
            cin>>alpha;
            cout<<"Enter beta(brightness) value: ";
            cin>>beta;
            image=adjustColor(image,alpha,beta);
            cout<<"Image color adjusted successfully."<<endl;
            break;
        }
        case 4:{
            int startX,startY, width, height;
            cout<<"Enter the startX position: ";
            cin>>startX;
            cout<<"Enter the startY position: ";
            cin>>startY;
            cout<<"Enter the width of the cropped area: ";
            cin>>width;
            cout<<"Enter the height of the cropped area: ";
            cin>>height;
            image=cropImage(image, startX, startY,width,height);
            cout<<"Image cropped successfully."<<endl;
            break;
        }
        case 5:{
            string saverFilename;
            cout<<"Enter the file name to save the image: ";
            cin>>saverFilename;
            saveImage(image, saverFilename);
            cout<<"Image saved successfully."<<endl;
            break;
        }
        case 0:
        cout<<"Exciting the program."<<endl;
        break;
        default:
        cout<<"Invalid choice! Please try again."<<endl;
        }
    }
    while(choice !=0);
    return 0;
}