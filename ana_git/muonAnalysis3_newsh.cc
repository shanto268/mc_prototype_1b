// c++  `root-config --cflags` -o muonAnalysis3 sc8muontree2.cc muonAnalysis3_newsh.cc `root-config --glibs`
//
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <cassert>
#include <vector>
#include <time.h>

#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TGraph.h"
#include "TProfile.h"
#include "TDirectory.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TStyle.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include "TRatioPlot.h"

#include "sc8muontree2.h"

using namespace std;

//   define a struct globally.
struct TrackPoint{
   TVector3 x3;
   TVector3 p3;
};

// ==========================================================================
class AnaMuon {
   public:
      AnaMuon(TFile * fout); 
      ~AnaMuon();
      void analyze(sc8muontree2 ev);
      void endjob();

   private:

      vector<TrackPoint>  reconstructTracks(sc8muontree2 ev);
      vector<TrackPoint>  estimateXYatZ(vector<double> zPlane,TrackPoint tk );

      std::map<std::string, TH1D*> histo1D;
      std::map<std::string, TH1D*>::iterator histo1Diter;

      std::map<std::string, TH2D*> histo2D;
      std::map<std::string, TH2D*>::iterator histo2Diter;
      ofstream myfile[2];
      double xme;
      double angle;
      //int printHitFlag;
      int event;
      vector<double> xe;
      vector<double> ang;
      vector<double> xe2;
      vector<double> ang2;
};
class Track {
   public:
      Track(double _x, double _y, double _xs, double _ys) {
        x=_x; y=_y; xs=_xs; ys=_ys;
      };
      double x;    // at z=0
      double y;    // at z=0
      double xs;   // xslope = (x0-x2)/(z0-z2)
      double ys;   // yslope = (y1-y3)/(z1-z3)
     // vector<Hit> hits;
};

// =========================================  zzanaMuon

AnaMuon::AnaMuon(TFile * fout) {
  std::string filename[2]= {"example.txt","example1.txt",/*"example2.txt"*/};

   for (int i = 0; i < 2; i++)
	{
		myfile[i].open(filename[i].c_str());
	} 
   //printHitFlag=0;
   event=1;
   xme=0;
   angle=0.0;
   xe.clear();
   ang.clear();
   fout->cd();
   //new code: start
   histo1D["L0Ch"]=new TH1D("L0Ch","L0 Channel Numbers",15,0.,15.);
   histo1D["L0Ch"]->GetXaxis()->SetTitle("Ch number 0 to 10");
   histo1D["L0Ch"]->GetYaxis()->SetTitle("Number of hits");
   histo1D["L1Ch"]=new TH1D("L1Ch","L1 Channel Numbers",15,0.,15.);
   histo1D["L1Ch"]->GetXaxis()->SetTitle("Ch number 0 to 10");
   histo1D["L1Ch"]->GetYaxis()->SetTitle("Number of hits");
   histo1D["L2Ch"]=new TH1D("L2Ch","L2 Channel Numbers",15,0.,15.);
   histo1D["L2Ch"]->GetXaxis()->SetTitle("Ch number 0 to 10");
   histo1D["L2Ch"]->GetYaxis()->SetTitle("Number of hits");
   histo1D["L3Ch"]=new TH1D("L3Ch","L3 Channel Numbers",15,0.,15.);
   histo1D["L3Ch"]->GetXaxis()->SetTitle("Ch number 0 to 10");
   histo1D["L3Ch"]->GetYaxis()->SetTitle("Number of hits");
   
  //new code: end
  //muX,Yproj
   int nbins = 200;   
   histo1D["GenP"]=new TH1D("GenP","Gen P (GeV)",100,0.,20.);
   histo1D["GenId"]=new TH1D("GenId","Gen Id",100,0.,20.);
   histo2D["GenXY"]=new TH2D("GenXY","Gen X vs Y (cm)",100,-100.0,100.0,100,-100.0,100.0);
/*
   histo1D["HitP"]=new TH1D("HitP","Hit P (GeV)",100,0.,100.);
   histo2D["HitXY"]=new TH2D("HitXY","Hit X vs Y (cm)",100,-100.0,100.0,100,-100.0,100.0);
*/
   histo1D["Layer1Edep"]=new TH1D("Layer1Edep","Layer1 Edep (MeV)",100,0.0,30.0);
   histo1D["Layer1Edep"]->GetXaxis()->SetTitle("X (MeV)");
   histo1D["Layer1ChId"]=new TH1D("Layer1ChId","Layer1 Channel ID (Edep weighted)",10,0.0,10.0);
   histo1D["Layer2Edep"]=new TH1D("Layer2Edep","Layer2 Edep (MeV)",100,0.0,30.0);
   histo1D["Layer2Edep"]->GetXaxis()->SetTitle("X (MeV)");
   histo1D["Layer2ChId"]=new TH1D("Layer2ChId","Layer2 Channel ID (Edep weighted)",10,0.0,10.0);
   histo1D["Layer3Edep"]=new TH1D("Layer3Edep","Layer3 Edep (MeV)",100,0.0,30.0);
   histo1D["Layer3Edep"]->GetXaxis()->SetTitle("X (MeV)");
   histo1D["Layer3ChId"]=new TH1D("Layer3ChId","Layer3 Channel ID (Edep weighted)",10,0.0,10.0);
   histo1D["Layer4Edep"]=new TH1D("Layer4Edep","Layer4 Edep (MeV)",100,0.0,30.0);
   histo1D["Layer4Edep"]->GetXaxis()->SetTitle("X (MeV)");
   histo1D["Layer4ChId"]=new TH1D("Layer4ChId","Layer4 Channel ID (Edep weighted)",10,0.0,10.0);

   histo1D["Layer1Step"]=new TH1D("Layer1Step","Layer1 Step (mm)",140,0.0,140.0);
   histo1D["Layer1Step"]->GetXaxis()->SetTitle("X (mm)");
   histo1D["Layer2Step"]=new TH1D("Layer2Step","Layer2 Step (mm)",140,0.0,140.0);
   histo1D["Layer2Step"]->GetXaxis()->SetTitle("X (mm)");
   histo1D["Layer3Step"]=new TH1D("Layer3Step","Layer3 Step (mm)",140,0.0,140.0);
   histo1D["Layer3Step"]->GetXaxis()->SetTitle("X (mm)");
   histo1D["Layer4Step"]=new TH1D("Layer4Step","Layer4 Step (mm)",140,0.0,140.0);
   histo1D["Layer4Step"]->GetXaxis()->SetTitle("X (mm)");
   
   histo1D["Tray1Yview"]=new TH1D("Tray1Yview","Y View T1",70,-35,35);
   histo1D["Tray1Yview"]->GetXaxis()->SetTitle("X (cm)");
   histo1D["Tray1Xview"]=new TH1D("Tray1Xview","X View T1",70,-35,35);
   histo1D["Tray1Xview"]->GetXaxis()->SetTitle("X (cm)");
   histo2D["Tray1XYview"]=new TH2D("Tray1XYview","XY View T1",60,-30,30,60,-30,30);
   histo2D["Tray1XYview5cm"]=new TH2D("Tray1XYview5cm","XY View T1 (5cm)",12,-30,30,12,-30,30);

   histo1D["Tray2Yview"]=new TH1D("Tray2Yview","Y View T2",70,-35,35);
   histo1D["Tray2Yview"]->GetXaxis()->SetTitle("X (cm)");
   histo1D["Tray2Xview"]=new TH1D("Tray2Xview","X View T2",70,-35,35);
   histo1D["Tray2Xview"]->GetXaxis()->SetTitle("X (cm)");
   histo2D["Tray2XYview"]=new TH2D("Tray2XYview","XY View T2",60,-30,30,60,-30,30);
   histo2D["Tray2XYview5cm"]=new TH2D("Tray2XYview5cm","XY View T2 (5cm)",12,-30,30,12,-30,30);
   
   histo1D["Tray1Yview5degreeT"]=new TH1D("Tray1Yview5degreeT","Y View T1 with 5 Degree Restriction (True)",70,-35,35);
   histo1D["Tray1Yview5degreeT"]->GetXaxis()->SetTitle("X (cm)");
   histo1D["Tray1Xview5degreeT"]=new TH1D("Tray1Xview5degreeT","X View T1 with 5 Degree Restriction (True)",70,-35,35);
   histo1D["Tray1Xview5degreeT"]->GetXaxis()->SetTitle("X (cm)");
   histo2D["Tray1XYview5degreeT"]=new TH2D("Tray1XYview5degreeT","XY View T1 with 5 Degree Restriction (True)",60,-30,30,60,-30,30);
   histo2D["Tray1XYview5degreeT5cm"]=new TH2D("Tray1XYview5degreeT5cm","XY View T1 with 5 Degree Restriction (True) (5cm)",12,-30,30,12,-30,30);

   histo1D["Tray2Yview5degreeT"]=new TH1D("Tray2Yview5degreeT","Y View T2 with 5 Degree Restriction (True)",70,-35,35);
   histo1D["Tray2Yview5degreeT"]->GetXaxis()->SetTitle("X (cm)");
   histo1D["Tray2Xview5degreeT"]=new TH1D("Tray2Xview5degreeT","X View T2 with 5 Degree Restriction (True)",70,-35,35);
   histo1D["Tray2Xview5degreeT"]->GetXaxis()->SetTitle("X (cm)");
   histo2D["Tray2XYview5degreeT"]=new TH2D("Tray2XYview5degreeT","XY View T2 with 5 Degree Restriction (True)",60,-30,30,60,-30,30);
   histo2D["Tray2XYview5degreeT5cm"]=new TH2D("Tray2XYview5degreeT5cm","XY View T2 with 5 Degree Restriction (True) (5cm)",12,-30,30,12,-30,30);

   histo1D["Tray1Yview5degreeTT"]=new TH1D("Tray1Yview5degreeTT","Y View T1 with 5 Degree Restriction (Track)",70,-35,35);
   histo1D["Tray1Yview5degreeTT"]->GetXaxis()->SetTitle("X (cm)");
   histo1D["Tray1Xview5degreeTT"]=new TH1D("Tray1Xview5degreeTT","X View T1 with 5 Degree Restriction (Track)",70,-35,35);
   histo1D["Tray1Xview5degreeTT"]->GetXaxis()->SetTitle("X (cm)");
   histo2D["Tray1XYview5degreeTT"]=new TH2D("Tray1XYview5degreeTT","XY View T1 with 5 Degree Restriction (Track)",60,-30,30,60,-30,30);
   histo2D["Tray1XYview5degreeTT5cm"]=new TH2D("Tray1XYview5degreeTT5cm","XY View T1 with 5 Degree Restriction (Track) (5cm)",12,-30,30,12,-30,30);

   histo1D["Tray2Yview5degreeTT"]=new TH1D("Tray2Yview5degreeTT","Y View T2 with 5 Degree Restriction (Track)",70,-35,35);
   histo1D["Tray2Yview5degreeTT"]->GetXaxis()->SetTitle("X (cm)");
   histo1D["Tray2Xview5degreeTT"]=new TH1D("Tray2Xview5degreeTT","X View T2 with 5 Degree Restriction (Track)",70,-35,35);
   histo1D["Tray2Xview5degreeTT"]->GetXaxis()->SetTitle("X (cm)");
   histo2D["Tray2XYview5degreeTT"]=new TH2D("Tray2XYview5degreeTT","XY View T2 with 5 Degree Restriction (Track)",60,-30,30,60,-30,30);
   histo2D["Tray2XYview5degreeTT5cm"]=new TH2D("Tray2XYview5degreeTT5cm","XY View T2 with 5 Degree Restriction (Track) (5cm)",12,-30,30,12,-30,30);

   histo1D["Theta35"]= new TH1D("Theta35","Angle from Zenith",70,0,35);
   histo1D["Theta35"]->GetXaxis()->SetTitle("X (degree)");
   histo1D["TrackTheta35"]= new TH1D("TrackTheta35","Track Angle from Zenith",19,0,36);
   histo1D["TrackTheta35"]->GetXaxis()->SetTitle("X (degree)");
   histo1D["TrackX"]= new TH1D("TrackX","TrackX",70,-10.0,60.0);
   histo1D["TrackY"]= new TH1D("TrackY","TrackY",70,-10.0,60.0);
   histo1D["TrackZ"]= new TH1D("TrackZ","TrackZ",70,-10.0,60.0);
   histo2D["TrackvGenTheta35"]=new TH2D("TrackvGenTheta35","Track vs Gen (Theta45)",70,0.0,35.0,70,0.0,35.0);

   histo1D["EdepTestObj"]= new TH1D("EdepTestObj","Edep Test Object",800,0.0,800);
   histo1D["EdepTestObj"]->GetXaxis()->SetTitle("X (MeV)");
   histo1D["StepTestObj"]= new TH1D("StepTestObj","Step Length Test Object",800,0.0,800);
   histo1D["StepTestObj"]->GetXaxis()->SetTitle("X (mm)");

   histo1D["YviewZPlane"]=new TH1D("YviewZPlane","Y View in Z Plane",100,-50,50);
   histo1D["XviewZPlane"]=new TH1D("XviewZPlane","X View in Z Plane",100,-50,50);
   histo2D["XYviewZPlane"]=new TH2D("XYviewZPlane","XY View in Z Plane",100,-50,50,100,-50,50);
   histo2D["XYviewZPlane5cm"]=new TH2D("XYviewZPlane5cm","XY View in Z Plane",20,-50,50,20,-50,50);

   histo1D["YviewZPlaneT"]=new TH1D("YviewZPlaneT","Y View in Z Plane with 5 Degree Restriction (True)",100,-50,50);
   histo1D["XviewZPlaneT"]=new TH1D("XviewZPlaneT","X View in Z Plane with 5 Degree Restriction (True)",100,-50,50);
   histo2D["XYviewZPlaneT"]=new TH2D("XYviewZPlaneT","XY View in Z Plane with 5 Degree Restriction (True)",100,-50,50,100,-50,50);
   histo2D["XYviewZPlaneT5cm"]=new TH2D("XYviewZPlaneT5cm","XY View in Z Plane with 5 Degree Restriction (True)",20,-50,50,20,-50,50);

   histo1D["YviewZPlaneTT"]=new TH1D("YviewZPlaneTT","Y View in Z Plane with 5 Degree Restriction (Track)",100,-50,50);
   histo1D["XviewZPlaneTT"]=new TH1D("XviewZPlaneTT","X View in Z Plane with 5 Degree Restriction (Track)",100,-50,50);
   histo2D["XYviewZPlaneTT"]=new TH2D("XYviewZPlaneTT","XY View in Z Plane with 5 Degree Restriction (Track)",100,-50,50,100,-50,50);
   histo2D["XYviewZPlaneTT5cm"]=new TH2D("XYviewZPlaneTT5cm","XY View in Z Plane with 5 Degree Restriction (Track)",20,-50,50,20,-50,50);

   
   int nz=20;
   double xylim=100.0;
   for (int i=0; i<nz; i++) {
     string hname="xZ"+to_string(i);
     string htitle="(reco) x at Z"+to_string(i);
     histo1D[hname]=new TH1D(hname.c_str(),htitle.c_str(),100,-xylim,xylim);
     histo1D[hname]->GetXaxis()->SetTitle("X distance [cm]");
     histo1D[hname]->GetYaxis()->SetTitle("Number of Events");
     string hname3="yZ"+to_string(i);
     string htitle3="(reco) y at Z"+to_string(i);
     histo1D[hname3]=new TH1D(hname3.c_str(),htitle3.c_str(),100,-xylim,xylim);
     histo1D[hname3]->GetXaxis()->SetTitle("Y distance [cm]");
     histo1D[hname3]->GetYaxis()->SetTitle("Number of Events");
     string hname2="xyZ"+to_string(i);
     string htitle2="(reco) x-y at Z"+to_string(i);
     histo2D[hname2]=new TH2D(hname2.c_str(),htitle2.c_str(),15,-xylim/2.0,xylim/2.0,15,-xylim/2.0,xylim/2.0);
     histo2D[hname2]->GetXaxis()->SetTitle("X projection");
     histo2D[hname2]->GetYaxis()->SetTitle("Y projection");
     /*
     string hname4="xyZ"+to_string(i)+"T";
     string htitle4="(reco) x-y at Z"+to_string(i)+"T";
     histo2D[hname4]=new TH2D(hname4.c_str(),htitle4.c_str(),15,-xylim/2.0,xylim/2.0,15,-xylim/2.0,xylim/2.0);
     histo2D[hname4]->GetXaxis()->SetTitle("X projection");
     histo2D[hname4]->GetYaxis()->SetTitle("Y projection");
     string hname5="xyZ"+to_string(i)+"TT";
     string htitle5="(reco) x-y at Z"+to_string(i)+"TT";
     histo2D[hname5]=new TH2D(hname5.c_str(),htitle5.c_str(),15,-xylim/2.0,xylim/2.0,15,-xylim/2.0,xylim/2.0);
     histo2D[hname5]->GetXaxis()->SetTitle("X projection");
     histo2D[hname5]->GetYaxis()->SetTitle("Y projection");*/
   } 
   
}
//---------------------------------------------------------------------
AnaMuon::~AnaMuon() {} ;

//---------------------------------------------------------------------
void AnaMuon::analyze(sc8muontree2 ev) {
   double zCry;
   double xmax,xmin,ymax,ymin;

   // reconstruct tracks...
   vector<TrackPoint> recoedTracks=reconstructTracks(ev);
   xe.clear();
   ang.clear();
   xe2.clear();
   ang2.clear();
   for(int i=0; i<ev.nGenPar; i++) {
     histo1D["GenP"]->Fill(ev.GenParP[i]);
     histo1D["GenId"]->Fill(ev.GenParId[i]);    
    
      double Pmev=ev.GenParP[i]*1000.0;
     histo2D["GenXY"]->Fill(ev.GenParVx[i],ev.GenParVy[i]);
     zCry=ev.GenParVz[i];   // z coordinate of muon source (CRY)...
   }  // end of loop over Gen Par.

  double muonangle = 999.0;
  for(int i=0; i<ev.nGenPar; i++) {
     int pid = ev.GenParId[i];
     if(pid == 13 || pid == -13){
     muonangle = atan(sqrt(pow(ev.GenParPx[i],2)+pow(ev.GenParPy[i],2))/abs(ev.GenParPz[i]))/(4*atan(1))*180.;
     //if(muonangle > 5.0) return;
     histo1D["Theta35"]->Fill(muonangle);
     if(muonangle < 5.0){
        histo1D["Tray1Yview5degreeT"]->Fill(ev.HitsT1Vy[i]);
        histo1D["Tray1Xview5degreeT"]->Fill(ev.HitsT1Vx[i]);
        histo2D["Tray1XYview5degreeT"]->Fill(ev.HitsT1Vx[i],ev.HitsT1Vy[i]);
        histo2D["Tray1XYview5degreeT5cm"]->Fill(ev.HitsT1Vx[i],ev.HitsT1Vy[i]);
        histo1D["Tray2Yview5degreeT"]->Fill(ev.HitsT2Vy[i]);
        histo1D["Tray2Xview5degreeT"]->Fill(ev.HitsT2Vx[i]);
        histo2D["Tray2XYview5degreeT"]->Fill(ev.HitsT2Vx[i],ev.HitsT2Vy[i]);
        histo2D["Tray2XYview5degreeT5cm"]->Fill(ev.HitsT2Vx[i],ev.HitsT2Vy[i]);
        histo1D["YviewZPlaneT"]->Fill(((ev.HitsT2Vy[i]-ev.HitsT1Vy[i])/162.6)*(55.8)+ev.HitsT2Vy[i]);
        histo1D["XviewZPlaneT"]->Fill(((ev.HitsT2Vx[i]-ev.HitsT1Vx[i])/162.6)*(55.8)+ev.HitsT2Vx[i]);
        histo2D["XYviewZPlaneT"]->Fill(((ev.HitsT2Vx[i]-ev.HitsT1Vx[i])/162.6)*(55.8)+ev.HitsT2Vx[i],((ev.HitsT2Vy[i]-ev.HitsT1Vy[i])/162.6)*(55.8)+ev.HitsT2Vy[i]);
        histo2D["XYviewZPlaneT5cm"]->Fill(((ev.HitsT2Vx[i]-ev.HitsT1Vx[i])/162.6)*(55.8)+ev.HitsT2Vx[i],((ev.HitsT2Vy[i]-ev.HitsT1Vy[i])/162.6)*(55.8)+ev.HitsT2Vy[i]);

     }
     }
   }

   int ntracks = recoedTracks.size();
   for(int i = 0;i < ntracks;i++){
      double x = recoedTracks[i].x3.x();
      double y = recoedTracks[i].x3.y();
      double z = recoedTracks[i].x3.z();
      double px = recoedTracks[i].p3.x();
      double py = recoedTracks[i].p3.y();
      double pz = recoedTracks[i].p3.z();
      double trackangle = atan(sqrt(pow(px,2)+pow(py,2))/abs(pz))/(4*atan(1))*180.;
      histo1D["TrackTheta35"]->Fill(trackangle);
      histo1D["TrackX"]->Fill(x);
      histo1D["TrackY"]->Fill(y);
      histo1D["TrackZ"]->Fill(z);
      //if(trackangle < 5.0) return;
      histo2D["TrackvGenTheta35"]->Fill(trackangle,muonangle);
      if(trackangle < 5.0){
        histo1D["Tray1Yview5degreeTT"]->Fill(ev.HitsT1Vy[i]);
        histo1D["Tray1Xview5degreeTT"]->Fill(ev.HitsT1Vx[i]);
        histo2D["Tray1XYview5degreeTT"]->Fill(ev.HitsT1Vx[i],ev.HitsT1Vy[i]);
        histo2D["Tray1XYview5degreeTT5cm"]->Fill(ev.HitsT1Vx[i],ev.HitsT1Vy[i]);
        histo1D["Tray2Yview5degreeTT"]->Fill(ev.HitsT2Vy[i]);
        histo1D["Tray2Xview5degreeTT"]->Fill(ev.HitsT2Vx[i]);
        histo2D["Tray2XYview5degreeTT"]->Fill(ev.HitsT2Vx[i],ev.HitsT2Vy[i]);
        histo2D["Tray2XYview5degreeTT5cm"]->Fill(ev.HitsT2Vx[i],ev.HitsT2Vy[i]);
        histo1D["YviewZPlaneTT"]->Fill(((ev.HitsT2Vy[i]-ev.HitsT1Vy[i])/162.6)*(55.8)+ev.HitsT2Vy[i]);
        histo1D["XviewZPlaneTT"]->Fill(((ev.HitsT2Vx[i]-ev.HitsT1Vx[i])/162.6)*(55.8)+ev.HitsT2Vx[i]);
        histo2D["XYviewZPlaneTT"]->Fill(((ev.HitsT2Vx[i]-ev.HitsT1Vx[i])/162.6)*(55.8)+ev.HitsT2Vx[i],((ev.HitsT2Vy[i]-ev.HitsT1Vy[i])/162.6)*(55.8)+ev.HitsT2Vy[i]);
        histo2D["XYviewZPlaneTT5cm"]->Fill(((ev.HitsT2Vx[i]-ev.HitsT1Vx[i])/162.6)*(55.8)+ev.HitsT2Vx[i],((ev.HitsT2Vy[i]-ev.HitsT1Vy[i])/162.6)*(55.8)+ev.HitsT2Vy[i]);
     }
   }

  for(int i=0; i<ev.nHitsT1; i++) {
      histo1D["Tray1Yview"]->Fill(ev.HitsT1Vy[i]);
      histo1D["Tray1Xview"]->Fill(ev.HitsT1Vx[i]);
      histo2D["Tray1XYview"]->Fill(ev.HitsT1Vx[i],ev.HitsT1Vy[i]);
      histo2D["Tray1XYview5cm"]->Fill(ev.HitsT1Vx[i],ev.HitsT1Vy[i]);
      //muonangle = atan(sqrt(pow(ev.GenParPx[i],2)+pow(ev.GenParPy[i],2))/abs(ev.GenParPz[i]))/(4*atan(1))*180.;
      /*if(muonangle < 5.0){
        histo1D["Tray1Yview5degreeT"]->Fill(ev.HitsT1Vy[i]);
        histo1D["Tray1Xview5degreeT"]->Fill(ev.HitsT1Vx[i]);
        histo2D["Tray1XYview5degreeT"]->Fill(ev.HitsT1Vx[i],ev.HitsT1Vy[i]);
     }*/
  }

  for(int i=0; i<ev.nHitsT2; i++) {
      histo1D["Tray2Yview"]->Fill(ev.HitsT2Vy[i]);
      histo1D["Tray2Xview"]->Fill(ev.HitsT2Vx[i]);
      histo2D["Tray2XYview"]->Fill(ev.HitsT2Vx[i],ev.HitsT2Vy[i]);
      histo2D["Tray2XYview5cm"]->Fill(ev.HitsT2Vx[i],ev.HitsT2Vy[i]);
      //muonangle = atan(sqrt(pow(ev.GenParPx[i],2)+pow(ev.GenParPy[i],2))/abs(ev.GenParPz[i]))/(4*atan(1))*180.;
      /*if(muonangle < 5.0){
        histo1D["Tray2Yview5degreeT"]->Fill(ev.HitsT2Vy[i]);
        histo1D["Tray2Xview5degreeT"]->Fill(ev.HitsT2Vx[i]);
        histo2D["Tray2XYview5degreeT"]->Fill(ev.HitsT2Vx[i],ev.HitsT2Vy[i]);
     }*/
  }

  for(int i=0; i<ev.nHitsT1; i++) {
     histo1D["YviewZPlane"]->Fill(((ev.HitsT2Vy[i]-ev.HitsT1Vy[i])/162.6)*(55.8)+ev.HitsT2Vy[i]);
     histo1D["XviewZPlane"]->Fill(((ev.HitsT2Vx[i]-ev.HitsT1Vx[i])/162.6)*(55.8)+ev.HitsT2Vx[i]);
     histo2D["XYviewZPlane"]->Fill(((ev.HitsT2Vx[i]-ev.HitsT1Vx[i])/162.6)*(55.8)+ev.HitsT2Vx[i],((ev.HitsT2Vy[i]-ev.HitsT1Vy[i])/162.6)*(55.8)+ev.HitsT2Vy[i]);
     histo2D["XYviewZPlane5cm"]->Fill(((ev.HitsT2Vx[i]-ev.HitsT1Vx[i])/162.6)*(55.8)+ev.HitsT2Vx[i],((ev.HitsT2Vy[i]-ev.HitsT1Vy[i])/162.6)*(55.8)+ev.HitsT2Vy[i]);
  }
  

//   RPs code...
   TrackPoint tkRef;
   for(int i=0; i<10; i++) {
     double edep1=ev.EdepS1[i];
     double edep2=ev.EdepS2[i];
     double edep3=ev.EdepS3[i];
     double edep4=ev.EdepS4[i];
     double e_cut=0.0; //threshold energy

     if(edep1>e_cut) {
         histo1D["L0Ch"]->Fill(i);
     }
     if(edep2>e_cut) {
         histo1D["L1Ch"]->Fill(i);
     }
     if(edep3>e_cut) {
         histo1D["L2Ch"]->Fill(i);
     }
     if(edep4>e_cut) {
         histo1D["L3Ch"]->Fill(i);
     }
     
   }   // end of for-loop over scint bars...

   for(int i=0; i<10; i++) {
     double step1=ev.SteplS1[i];
     double step2=ev.SteplS2[i];
     double step3=ev.SteplS3[i];
     double step4=ev.SteplS4[i];
     double s_cut= 0.0;
     if(step1>s_cut){
     histo1D["Layer1Step"]->Fill(step1);
     }
     if(step2>s_cut){
     histo1D["Layer2Step"]->Fill(step2);
     }
     if(step3>s_cut){
     histo1D["Layer3Step"]->Fill(step3);
     }
     if(step4>s_cut){
     histo1D["Layer4Step"]->Fill(step4);
     }
   } 

   double edeptest = ev.EdepTestObj;
   double te_cut=0.0; //threshold energy
   if(edeptest>te_cut) {
      histo1D["EdepTestObj"]->Fill(edeptest);
   }

   double steptest=ev.mStepTestObj;
   double ts_cut= 0.0;
   if(steptest>ts_cut){
      histo1D["StepTestObj"]->Fill(steptest);
   }

// muon tracks ... rp

   int nhits=0;
   double xx=0;
   for(int i=0; i<10; i++) {
     double edep=ev.EdepS1[i];
     double edep2=ev.EdepS2[i];
     double edep3=ev.EdepS3[i];
     double edep4=ev.EdepS4[i];
     if(edep>0.0) {
       histo1D["Layer1Edep"]->Fill(edep);
       histo1D["Layer1ChId"]->Fill(double(i),edep);
       nhits=nhits+1;
     }
     if(edep2>0.0) {
       histo1D["Layer2Edep"]->Fill(edep2);
       histo1D["Layer2ChId"]->Fill(double(i),edep2);
     }
     if(edep3>0.0) {
       histo1D["Layer3Edep"]->Fill(edep3);
       histo1D["Layer3ChId"]->Fill(double(i),edep3);
     }
     if(edep4>0.0) {
       histo1D["Layer4Edep"]->Fill(edep4);
       histo1D["Layer4ChId"]->Fill(double(i),edep4);
     }
   }
     // end of loop over scinti bars..   

//   createzplane where we check the position of tracks.
     double zRef=0.0;
     double nz=20.0;
     double dz=(250.0-zRef)/nz;
     vector<double> zPlane;
     for (int i=0; i<nz; i++) { 
        double z=dz*i;
        zPlane.push_back(z); 
     }

//  use recoedTracks...

   if(recoedTracks.size()>0) {
     //  get hits in planes at different elevation (z)...  
     //  just use the first track for nwow.
    vector<TrackPoint>  tkZs=estimateXYatZ(zPlane,recoedTracks[0]);
     for (int i=0; i<tkZs.size(); i++) {
        double x=tkZs[i].x3.x();
        double y=tkZs[i].x3.y();
        if(i==5){
           xme=tkZs[i].x3.x();
           angle=atan(tkZs[i].p3.x()/tkZs[i].p3.z());
            
        }
        string hname="xZ"+to_string(i);
        if(y>-5000.0 && y<5000.0) {
           histo1D[hname]->Fill(x);
        }
        string hname3="yZ"+to_string(i);
        if(x>-5000.0 && x<5000.0) {
           histo1D[hname3]->Fill(y);
        }
        string hname2="xyZ"+to_string(i);
        histo2D[hname2]->Fill(x,y);
    }  // end of if(recoedTracks.size()>0)
    event=event+1; 
   }
}  // end of AnaMuon::analyze

//=============================================================================
void AnaMuon::endjob() {
myfile[0].close();
myfile[1].close();
}
//=============================================================================
vector<TrackPoint>  AnaMuon::estimateXYatZ(vector<double> zPlane,TrackPoint tk ) {
   vector<TrackPoint> tkout;
     int nZplanes=zPlane.size();
     if(nZplanes>0) {
        for (int i=0; i<nZplanes; i++) {
          double dz=zPlane[i]-tk.x3.z();
          double x=dz*(tk.p3.x()/tk.p3.z())+tk.x3.x();
          double y=dz*(tk.p3.y()/tk.p3.z())+tk.x3.y();
          double z=zPlane[i];
          // cout<<"   in estimate   x"<<x<<"  y "<<y<<"  z "<<z<<endl;
          // cout<<"      zPlane[i] "<<zPlane[i]<<"  tk.x3.z() "<<tk.x3.z()<<endl; 
          TVector3 xx(x,y,z);
          
          TrackPoint tkTmp;
          tkTmp.x3=xx;
          tkTmp.p3=tk.p3;  // track vector does not change.
          tkout.push_back(tkTmp);
       // }
     }
   }  // end of if if(abs(tk.x3.x())<25.0 && abs(tk.x3.y()) <25.0) {
   return tkout;;
}

//=============================================================================
vector<TrackPoint>  AnaMuon::reconstructTracks(sc8muontree2 ev ) {
   vector<TrackPoint> recoedTracks;
   // layer 1 and 3 measure the y-corrdinate 
   // layer 2 and 4 measure the z-coordinate
   double zpos[]={0.0, 59.373+25.67, 51.88+25.67, -51.88-25.67, -59.373-25.67};  // index 0 is dummy
   vector<double> y1,y3;
   vector<double> x2,x4;

   //  store x and y coordinates...
   double xesum[]={0.0, 0.0, 0.0, 0.0, 0.0};
   double esum[]= {0.0, 0.0, 0.0, 0.0, 0.0};
   
   for(int i=0; i<10; i++) {
     double edep1=ev.EdepS1[i];   // y1
     double edep2=ev.EdepS2[i];   // x2
     double edep3=ev.EdepS3[i];   // y3
     double edep4=ev.EdepS4[i];   // x4
     
     double xyval=5.0*i-22.5;

     if(edep1>0.0) {xesum[1]=xesum[1]+edep1*xyval; esum[1]=esum[1]+edep1;}
     if(edep2>0.0) {xesum[2]=xesum[2]+edep2*xyval; esum[2]=esum[2]+edep2;}
     if(edep3>0.0) {xesum[3]=xesum[3]+edep3*xyval; esum[3]=esum[3]+edep3;}
     if(edep4>0.0) {xesum[4]=xesum[4]+edep4*xyval; esum[4]=esum[4]+edep4;}
   } // end of for loop

   double a;
   if(esum[1]>0.0) {a=xesum[1]/esum[1]; y1.push_back(a);}
   if(esum[2]>0.0) {a=xesum[2]/esum[2]; x2.push_back(a);}
   if(esum[3]>0.0) {a=xesum[3]/esum[3]; y3.push_back(a);}
   if(esum[4]>0.0) {a=xesum[4]/esum[4]; x4.push_back(a);}
   // reconstruct tracks...
   if(y1.size()==1 && y3.size()==1 && x2.size()==1 && x4.size()==1) {
      for(int iy1=0; iy1<y1.size(); iy1++) {
      for(int iy3=0; iy3<y3.size(); iy3++) {
        double yslope=(y3[iy3]-y1[iy1])/(zpos[3]-zpos[1]);
        double ypos=y1[iy1]+yslope*(0.0-zpos[1]);
        // calculate x slopes
        for(int ix2=0; ix2<x2.size(); ix2++) {
        for(int ix4=0; ix4<x4.size(); ix4++) {
          double xslope=(x4[ix4]-x2[ix2])/(zpos[4]-zpos[2]);
          double xpos=x2[ix2]+xslope*(0.0-zpos[2]);
         TrackPoint tkTemp;
         TVector3 xx(xpos,ypos,0.0); 
         TVector3 pp(xslope,yslope,1.0); 
         tkTemp.x3=xx;
         tkTemp.p3=pp;         
         recoedTracks.push_back(tkTemp);
        }  // end of loop over x4
        }  // end of loop over x2.
      }  // end of loop over y3.
      }  // end of loop over y1.
   }
   return recoedTracks;
}  // end of AnaMuon::reconstructTracks

// ==========================================================================
int main(int argc, char **argv) {

   string inputFileName=argv[1];
   string outputFileName=argv[2];
   cout<<"Input file name="<<inputFileName<<endl;
   cout<<"Output file name="<<outputFileName<<endl;
   TFile *fout = new TFile(outputFileName.c_str(),"recreate");

   AnaMuon ana(fout);

   TFile fin(inputFileName.c_str());

   TTree * tree;
   fin.GetObject("tree",tree);

   //   print out ntuple data structure...
   // tree->Print();

   sc8muontree2 ev;
   ev.Init(tree);

   int nentries = tree->GetEntriesFast();
  
   cout<<"nentries  "<<nentries<<endl;

   int nMax=1000000000;
   int nn=0;
   while ( ev.GetEntry(nn)){
       nn++;
       if(nn>nMax) break;
       ana.analyze(ev);
   } // end of event loop.

   ana.endjob();

   fout->Write();
   fout->Close();

}

