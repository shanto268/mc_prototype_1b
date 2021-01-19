#include <fstream>
#include <iostream>
{
   std::map<std::string, TH1D*> histo1D;
   std::map<std::string, TH1D*>::iterator histo1Diter;

   std::map<std::string, TH2D*> histo2D;
   std::map<std::string, TH2D*>::iterator histo2Diter;

   TFile *f1 = new TFile("away.root","READ"); //away
   TFile *f2 = new TFile("towards.root","READ"); //towards

   TH1D* GenPaway=(TH1D*)f1->Get("GenP");
   TH1D* GenPtank=(TH1D*)f2->Get("GenP");

   TH1D* Tray1Xaway=(TH1D*)f1->Get("Tray1Xview");
   TH1D* Tray1Xtank=(TH1D*)f2->Get("Tray1Xview");

   TH1D* Tray1Yaway=(TH1D*)f1->Get("Tray1Yview");
   TH1D* Tray1Ytank=(TH1D*)f2->Get("Tray1Yview");

   TH2D* Tray1XYaway=(TH2D*)f1->Get("Tray1XYview");
   TH2D* Tray1XYtank=(TH2D*)f2->Get("Tray1XYview");

   TH2D* Tray1XY5cmaway=(TH2D*)f1->Get("Tray1XYview5cm");
   TH2D* Tray1XY5cmtank=(TH2D*)f2->Get("Tray1XYview5cm");

   TH1D* Tray2Xaway=(TH1D*)f1->Get("Tray2Xview");
   TH1D* Tray2Xtank=(TH1D*)f2->Get("Tray2Xview");

   TH1D* Tray2Yaway=(TH1D*)f1->Get("Tray2Yview");
   TH1D* Tray2Ytank=(TH1D*)f2->Get("Tray2Yview");

   TH2D* Tray2XYaway=(TH2D*)f1->Get("Tray2XYview");
   TH2D* Tray2XYtank=(TH2D*)f2->Get("Tray2XYview");

   TH1D* Theta35away=(TH1D*)f1->Get("Theta35");
   TH1D* Theta35tank=(TH1D*)f2->Get("Theta35");

   TH1D* TrackTheta35away=(TH1D*)f1->Get("TrackTheta35");
   TH1D* TrackTheta35tank=(TH1D*)f2->Get("TrackTheta35");

   TH2D* TrackvGenTheta35away=(TH2D*)f1->Get("TrackvGenTheta35");
   TH2D* TrackvGenTheta35tank=(TH2D*)f2->Get("TrackvGenTheta35");

   //Edeps and step lenght on Bars

   TH1D* Layer1Edepaway=(TH1D*)f1->Get("Layer1Edep");
   TH1D* Layer1Edeptank=(TH1D*)f2->Get("Layer1Edep");

   TH1D* Layer2Edepaway=(TH1D*)f1->Get("Layer2Edep");
   TH1D* Layer2Edeptank=(TH1D*)f2->Get("Layer2Edep");

   TH1D* Layer3Edepaway=(TH1D*)f1->Get("Layer3Edep");
   TH1D* Layer3Edeptank=(TH1D*)f2->Get("Layer3Edep");

   TH1D* Layer4Edepaway=(TH1D*)f1->Get("Layer4Edep");
   TH1D* Layer4Edeptank=(TH1D*)f2->Get("Layer4Edep");

   TH1D* Layer1Stepaway=(TH1D*)f1->Get("Layer1Step");
   TH1D* Layer1Steptank=(TH1D*)f2->Get("Layer1Step");

   TH1D* Layer2Stepaway=(TH1D*)f1->Get("Layer2Step");
   TH1D* Layer2Steptank=(TH1D*)f2->Get("Layer2Step");

   TH1D* Layer3Stepaway=(TH1D*)f1->Get("Layer3Step");
   TH1D* Layer3Steptank=(TH1D*)f2->Get("Layer3Step");

   TH1D* Layer4Stepaway=(TH1D*)f1->Get("Layer4Step");
   TH1D* Layer4Steptank=(TH1D*)f2->Get("Layer4Step");

   TH1D* EdepTestObjtank=(TH1D*)f2->Get("EdepTestObj");
   TH1D* StepTestObjtank=(TH1D*)f2->Get("StepTestObj");

   //Z plane compare

   TH1D* XviewZPlaneaway=(TH1D*)f1->Get("XviewZPlane");
   TH1D* XviewZPlanetank=(TH1D*)f2->Get("XviewZPlane");

   TH1D* YviewZPlaneaway=(TH1D*)f1->Get("YviewZPlane");
   TH1D* YviewZPlanetank=(TH1D*)f2->Get("YviewZPlane");

   TH2D* XYviewZPlaneaway=(TH2D*)f1->Get("XYviewZPlane");
   TH2D* XYviewZPlanetank=(TH2D*)f2->Get("XYviewZPlane");
   
   TH2D* XYviewZPlane5cmaway=(TH2D*)f1->Get("XYviewZPlane5cm");
   TH2D* XYviewZPlane5cmtank=(TH2D*)f2->Get("XYviewZPlane5cm");

   TH1D* xyZ15away=(TH1D*)f1->Get("xyZ15");
   TH1D* xyZ15tank=(TH1D*)f2->Get("xyZ15");

   //5 degree Restriction

   TH1D* Tray1X5degreeTaway=(TH1D*)f1->Get("Tray1Xview5degreeT");
   TH1D* Tray1X5degreeTtank=(TH1D*)f2->Get("Tray1Xview5degreeT");

   TH1D* Tray1Y5degreeTaway=(TH1D*)f1->Get("Tray1Yview5degreeT");
   TH1D* Tray1Y5degreeTtank=(TH1D*)f2->Get("Tray1Yview5degreeT");

   TH2D* Tray1XY5degreeTaway=(TH2D*)f1->Get("Tray1XYview5degreeT");
   TH2D* Tray1XY5degreeTtank=(TH2D*)f2->Get("Tray1XYview5degreeT");

   TH2D* Tray1XY5degreeT5cmaway=(TH2D*)f1->Get("Tray1XYview5degreeT5cm");
   TH2D* Tray1XY5degreeT5cmtank=(TH2D*)f2->Get("Tray1XYview5degreeT5cm");

   TH1D* Tray2X5degreeTaway=(TH1D*)f1->Get("Tray2Xview5degreeT");
   TH1D* Tray2X5degreeTtank=(TH1D*)f2->Get("Tray2Xview5degreeT");

   TH1D* Tray2Y5degreeTaway=(TH1D*)f1->Get("Tray2Yview5degreeT");
   TH1D* Tray2Y5degreeTtank=(TH1D*)f2->Get("Tray2Yview5degreeT");

   TH2D* Tray2XY5degreeTaway=(TH2D*)f1->Get("Tray2XYview5degreeT");
   TH2D* Tray2XY5degreeTtank=(TH2D*)f2->Get("Tray2XYview5degreeT");

   TH2D* Tray2XY5degreeT5cmaway=(TH2D*)f1->Get("Tray2XYview5degreeT5cm");
   TH2D* Tray2XY5degreeT5cmtank=(TH2D*)f2->Get("Tray2XYview5degreeT5cm");

   TH1D* Tray1X5degreeTTaway=(TH1D*)f1->Get("Tray1Xview5degreeTT");
   TH1D* Tray1X5degreeTTtank=(TH1D*)f2->Get("Tray1Xview5degreeTT");

   TH1D* Tray1Y5degreeTTaway=(TH1D*)f1->Get("Tray1Yview5degreeTT");
   TH1D* Tray1Y5degreeTTtank=(TH1D*)f2->Get("Tray1Yview5degreeTT");

   TH2D* Tray1XY5degreeTTaway=(TH2D*)f1->Get("Tray1XYview5degreeTT");
   TH2D* Tray1XY5degreeTTtank=(TH2D*)f2->Get("Tray1XYview5degreeTT");

   TH2D* Tray1XY5degreeTT5cmaway=(TH2D*)f1->Get("Tray1XYview5degreeTT5cm");
   TH2D* Tray1XY5degreeTT5cmtank=(TH2D*)f2->Get("Tray1XYview5degreeTT5cm");

   TH1D* Tray2X5degreeTTaway=(TH1D*)f1->Get("Tray2Xview5degreeTT");
   TH1D* Tray2X5degreeTTtank=(TH1D*)f2->Get("Tray2Xview5degreeTT");

   TH1D* Tray2Y5degreeTTaway=(TH1D*)f1->Get("Tray2Yview5degreeTT");
   TH1D* Tray2Y5degreeTTtank=(TH1D*)f2->Get("Tray2Yview5degreeTT");

   TH2D* Tray2XY5degreeTTaway=(TH2D*)f1->Get("Tray2XYview5degreeTT");
   TH2D* Tray2XY5degreeTTtank=(TH2D*)f2->Get("Tray2XYview5degreeTT");

   TH2D* Tray2XY5degreeTT5cmaway=(TH2D*)f1->Get("Tray2XYview5degreeTT5cm");
   TH2D* Tray2XY5degreeTT5cmtank=(TH2D*)f2->Get("Tray2XYview5degreeTT5cm");

   TH1D* XviewZPlaneTaway=(TH1D*)f1->Get("XviewZPlaneT");
   TH1D* XviewZPlaneTtank=(TH1D*)f2->Get("XviewZPlaneT");

   TH1D* YviewZPlaneTaway=(TH1D*)f1->Get("YviewZPlaneT");
   TH1D* YviewZPlaneTtank=(TH1D*)f2->Get("YviewZPlaneT");

   TH2D* XYviewZPlaneTaway=(TH2D*)f1->Get("XYviewZPlaneT");
   TH2D* XYviewZPlaneTtank=(TH2D*)f2->Get("XYviewZPlaneT");
   
   TH2D* XYviewZPlaneT5cmaway=(TH2D*)f1->Get("XYviewZPlaneT5cm");
   TH2D* XYviewZPlaneT5cmtank=(TH2D*)f2->Get("XYviewZPlaneT5cm");

   TH1D* XviewZPlaneTTaway=(TH1D*)f1->Get("XviewZPlaneTT");
   TH1D* XviewZPlaneTTtank=(TH1D*)f2->Get("XviewZPlaneTT");

   TH1D* YviewZPlaneTTaway=(TH1D*)f1->Get("YviewZPlaneTT");
   TH1D* YviewZPlaneTTtank=(TH1D*)f2->Get("YviewZPlaneTT");

   TH2D* XYviewZPlaneTTaway=(TH2D*)f1->Get("XYviewZPlaneTT");
   TH2D* XYviewZPlaneTTtank=(TH2D*)f2->Get("XYviewZPlaneTT");
   
   TH2D* XYviewZPlaneTT5cmaway=(TH2D*)f1->Get("XYviewZPlaneTT5cm");
   TH2D* XYviewZPlaneTT5cmtank=(TH2D*)f2->Get("XYviewZPlaneTT5cm");

   TH1D* X1Tt=(TH1D*)Tray1Xtank->Clone();
   TH1D* Y1Tt=(TH1D*)Tray1Ytank->Clone();
   TH1D* X2Tt=(TH1D*)Tray2Xtank->Clone();
   TH1D* Y2Tt=(TH1D*)Tray2Ytank->Clone();
   TH1D* T35t=(TH1D*)Theta35tank->Clone();
   TH1D* TT35t=(TH1D*)TrackTheta35tank->Clone();
   TH1D* L1Edep=(TH1D*)Layer1Edeptank->Clone();
   TH1D* L2Edep=(TH1D*)Layer2Edeptank->Clone();
   TH1D* L3Edep=(TH1D*)Layer3Edeptank->Clone();
   TH1D* L4Edep=(TH1D*)Layer4Edeptank->Clone();
   TH1D* L1Step=(TH1D*)Layer1Steptank->Clone();
   TH1D* L2Step=(TH1D*)Layer2Steptank->Clone();
   TH1D* L3Step=(TH1D*)Layer3Steptank->Clone();
   TH1D* L4Step=(TH1D*)Layer4Steptank->Clone();
   TH1D* XPz=(TH1D*)XviewZPlanetank->Clone();
   TH1D* YPz=(TH1D*)YviewZPlanetank->Clone();
   TH1D* XPzT=(TH1D*)XviewZPlaneTtank->Clone();
   TH1D* YPzT=(TH1D*)YviewZPlaneTtank->Clone();
   TH1D* XPzTT=(TH1D*)XviewZPlaneTtank->Clone();
   TH1D* YPzTT=(TH1D*)YviewZPlaneTtank->Clone();
   TH1D* X1T=(TH1D*)Tray1X5degreeTtank->Clone();
   TH1D* Y1T=(TH1D*)Tray1Y5degreeTtank->Clone();
   TH1D* X2T=(TH1D*)Tray2X5degreeTtank->Clone();
   TH1D* Y2T=(TH1D*)Tray2Y5degreeTtank->Clone();
   TH1D* X1TT=(TH1D*)Tray1X5degreeTTtank->Clone();
   TH1D* Y1TT=(TH1D*)Tray1Y5degreeTTtank->Clone();
   TH1D* X2TT=(TH1D*)Tray2X5degreeTTtank->Clone();
   TH1D* Y2TT=(TH1D*)Tray2Y5degreeTTtank->Clone();

   TH1D* GPt=(TH1D*)GenPtank->Clone();
  
   int nxi=Tray1XYaway->GetNbinsY();
   int nyi=Tray1XYaway->GetNbinsX();
   TH2D* Tray1XYratio=new TH2D("Tray1XYratio","Tray 1 XY View Ratio",60,-30,30.0,60,-30.0,30.0);
     for (int ix=1; ix<=nxi; ix++) {
      for(int iy=1; iy<=nyi; iy++) {
         double wtA=Tray1XYaway->GetBinContent(ix,iy);
         double wtT=Tray1XYtank->GetBinContent(ix,iy);
         double wt=wtT/wtA;
         if(wt>1.1) wt=1.1;
         if(wt<0.5) wt=0.5;
         double y=-31+iy;
         double x=-31+ix;
         Tray1XYratio->Fill(x,y,wt);
        }
   }

   Tray1XYratio->GetXaxis()->SetTitle("X (cm)");
   Tray1XYratio->GetYaxis()->SetTitle("Y (cm)");
   //Tray1XYratio->GetZaxis()->SetRangeUser(0.5, 1.5);

   int nx5i=Tray1XY5cmaway->GetNbinsY();
   int ny5i=Tray1XY5cmaway->GetNbinsX();
   TH2D* Tray1XYratio5cm=new TH2D("Tray1XYratio5cm","Tray 1 XY View Ratio (5cm)",12,-30,30.0,12,-30.0,30.0);
     for (int ix=1; ix<=nx5i; ix++) {
      for(int iy=1; iy<=ny5i; iy++) {
         double wtA=Tray1XY5cmaway->GetBinContent(ix,iy);
         double wtT=Tray1XY5cmtank->GetBinContent(ix,iy);
         double wt=wtT/wtA;
         if(wt>1.1) wt=1.1;
         if(wt<0.5) wt=0.5;
         double y=-35+iy*5;
         double x=-35+ix*5;
         Tray1XYratio5cm->Fill(x,y,wt);
        }
   }

   Tray1XYratio5cm->GetXaxis()->SetTitle("X (cm)");
   Tray1XYratio5cm->GetYaxis()->SetTitle("Y (cm)");
   //Tray1XYratio5cm->GetZaxis()->SetRangeUser(0.5, 1.5);

   TCanvas *c98 = new TCanvas("c98","c98",400,300);
   Tray1XYratio->Draw("colz hist");
   c98->SaveAs("01_Tray1XYratio.png");

   TCanvas *c99 = new TCanvas("c99","c99",400,300);
   Tray1XYratio5cm->Draw("colz hist");
   c99->SaveAs("02_Tray1XYratio5cm.png");

   //
   // General Position (Ratio and Comparisons)
   //

   // Tray One
   TCanvas *c1 = new TCanvas("c1","c1",400,300);
   Tray1Xtank->SetLineColorAlpha(4, 0.35);
   Tray1Xaway->SetLineColorAlpha(2, 0.35);
   Tray1Xaway->Draw();
   X1Tt->Draw("same hist"); 
   c1->SetGrid();
   c1->SaveAs("03_X1viewcompare.png");

   TCanvas *c2 = new TCanvas("c2","c2",400,300);
   Tray1Xtank->SetLineColorAlpha(4, 0.35);
   Tray1Xtank->Draw();
   Tray1Xaway->Draw("same hist");
   Tray1Xtank->Divide(Tray1Xaway);
   Tray1Xtank->Draw();
   c2->SetGrid();
   c2->SaveAs("04_X1viewratio.png");

   TCanvas *c3 = new TCanvas("c3","c3",400,300);
   Tray1Ytank->SetLineColorAlpha(4, 0.35);
   Tray1Yaway->SetLineColorAlpha(2, 0.35);
   Tray1Yaway->Draw();
   Y1Tt->Draw("same hist"); 
   c3->SetGrid();
   c3->SaveAs("05_Y1viewcompare.png");

   TCanvas *c4 = new TCanvas("c4","c4",400,300);
   Tray1Ytank->SetLineColorAlpha(4, 0.35);
   Tray1Ytank->Draw();
   Tray1Yaway->Draw("same hist");
   Tray1Ytank->Divide(Tray1Yaway);
   Tray1Ytank->Draw();
   c4->SetGrid();
   c4->SaveAs("06_Y1viewratio.png");

   //Tray Two

   TCanvas *c5 = new TCanvas("c5","c5",400,300);
   Tray2Xtank->SetLineColorAlpha(4, 0.35);
   Tray2Xaway->SetLineColorAlpha(2, 0.35);
   Tray2Xaway->Draw();
   X2Tt->Draw("same hist");  
   c5->SetGrid();
   c5->SaveAs("07_X2viewcompare.png");

   TCanvas *c6 = new TCanvas("c6","c6",400,300);
   Tray2Xtank->SetLineColorAlpha(4, 0.35);
   Tray2Xtank->Draw();
   Tray2Xaway->Draw("same hist");
   Tray2Xtank->Divide(Tray2Xaway);
   Tray2Xtank->Draw();
   c6->SetGrid();
   c6->SaveAs("08_X2viewratio.png");

   TCanvas *c7 = new TCanvas("c7","c7",400,300);
   Tray2Ytank->SetLineColorAlpha(4, 0.35);
   Tray2Yaway->SetLineColorAlpha(2, 0.35);
   Tray2Yaway->Draw();
   Y2Tt->Draw("same hist");  
   c7->SetGrid();
   c7->SaveAs("09_Y2viewcompare.png");

   TCanvas *c8 = new TCanvas("c8","c8",400,300);
   Tray2Ytank->SetLineColorAlpha(4, 0.35);
   Tray2Ytank->Draw();
   Tray2Yaway->Draw("same hist");
   Tray2Ytank->Divide(Tray2Yaway);
   Tray2Ytank->Draw();
   c8->SetGrid();
   c8->SaveAs("10_Y2viewratio.png");

   //
   // Angles (in Degrees)
   //

   TCanvas *c9 = new TCanvas("c9","c9",400,300);
   Theta35tank->SetLineColorAlpha(4, 0.35);
   Theta35away->SetLineColorAlpha(2, 0.35);
   Theta35away->Draw();
   T35t->Draw("same hist");  
   c9->SetGrid();
   c9->SaveAs("11_Theta35compare.png");

   TCanvas *c10 = new TCanvas("c10","c10",400,300);
   Theta35tank->SetLineColorAlpha(4, 0.35);
   Theta35tank->Draw();
   Theta35away->Draw("same hist");
   Theta35tank->Divide(Theta35away);
   Theta35tank->Draw();
   c10->SetGrid();
   c10->SaveAs("12_Theta35ratio.png");

   TCanvas *c11 = new TCanvas("c11","c11",400,300);
   TrackTheta35tank->SetLineColorAlpha(4, 0.35);
   TrackTheta35away->SetLineColorAlpha(2, 0.35);
   TrackTheta35away->Draw();
   TT35t->Draw("same hist");  
   c11->SetGrid();
   c11->SaveAs("13_TrackTheta35compare.png");

   TCanvas *c12 = new TCanvas("c12","c12",400,300);
   TrackTheta35tank->SetLineColorAlpha(4, 0.35);
   TrackTheta35tank->Draw();
   TrackTheta35away->Draw("same hist");
   TrackTheta35tank->Divide(TrackTheta35away);
   TrackTheta35tank->Draw();
   c12->SetGrid();
   c12->SaveAs("14_TrackTheta35ratio.png");


   TCanvas *c13 = new TCanvas("c13","c13",400,300);
   TrackvGenTheta35tank->SetLineColorAlpha(4, 0.35);
   TrackvGenTheta35tank->Draw("colz hist");
   c13->SaveAs("15_TrackvGenThetaTestobj.png");

   TCanvas *c14 = new TCanvas("c14","c14",400,300);
   TrackvGenTheta35away->SetLineColorAlpha(4, 0.35);
   TrackvGenTheta35away->Draw("colz hist");
   c14->SaveAs("16_TrackvGenThetaair.png");

   //
   //Energy on Bar
   //

   TCanvas *c15 = new TCanvas("c15","c15",400,300);
   Layer1Edeptank->SetLineColorAlpha(4, 0.35);
   Layer1Edepaway->SetLineColorAlpha(2, 0.35);
   Layer1Edepaway->Draw();
   L1Edep->Draw("same hist");  
   c15->SetGrid();
   c15->SaveAs("17_Layer1Edepcompare.png");

   TCanvas *c16 = new TCanvas("c16","c16",400,300);
   Layer1Edeptank->SetLineColorAlpha(4, 0.35);
   Layer1Edeptank->Draw();
   Layer1Edepaway->Draw("same hist");
   Layer1Edeptank->Divide(Layer1Edepaway);
   Layer1Edeptank->Draw();
   c16->SetGrid();
   c16->SaveAs("18_Layer1Edepratio.png");

   TCanvas *c17 = new TCanvas("c17","c17",400,300);
   Layer2Edeptank->SetLineColorAlpha(4, 0.35);
   Layer2Edepaway->SetLineColorAlpha(2, 0.35);
   Layer2Edepaway->Draw();
   L2Edep->Draw("same hist"); 
   c17->SetGrid(); 
   c17->SaveAs("19_Layer2Edepcompare.png");

   TCanvas *c18 = new TCanvas("c18","c18",400,300);
   Layer2Edeptank->SetLineColorAlpha(4, 0.35);
   Layer2Edeptank->Draw();
   Layer2Edepaway->Draw("same hist");
   Layer2Edeptank->Divide(Layer2Edepaway);
   Layer2Edeptank->Draw();
   c18->SetGrid();
   c18->SaveAs("20_Layer2Edepratio.png");

   TCanvas *c19 = new TCanvas("c19","c19",400,300);
   Layer3Edeptank->SetLineColorAlpha(4, 0.35);
   Layer3Edepaway->SetLineColorAlpha(2, 0.35);
   Layer3Edepaway->Draw();
   L3Edep->Draw("same hist");  
   c19->SetGrid();
   c19->SaveAs("21_Layer3Edepcompare.png");

   TCanvas *c20 = new TCanvas("c20","c20",400,300);
   Layer3Edeptank->SetLineColorAlpha(4, 0.35);
   Layer3Edeptank->Draw();
   Layer3Edepaway->Draw("same hist");
   Layer3Edeptank->Divide(Layer3Edepaway);
   Layer3Edeptank->Draw();
   c20->SetGrid();
   c20->SaveAs("22_Layer3Edepratio.png");

   TCanvas *c21 = new TCanvas("c21","c21",400,300);
   Layer4Edeptank->SetLineColorAlpha(4, 0.35);
   Layer4Edepaway->SetLineColorAlpha(2, 0.35);
   Layer4Edepaway->Draw();
   L4Edep->Draw("same hist");  
   c21->SetGrid();
   c21->SaveAs("23_Layer4Edepcompare.png");

   TCanvas *c22 = new TCanvas("c22","c22",400,300);
   Layer4Edeptank->SetLineColorAlpha(4, 0.35);
   Layer4Edeptank->Draw();
   Layer4Edepaway->Draw("same hist");
   Layer4Edeptank->Divide(Layer4Edepaway);
   Layer4Edeptank->Draw();
   c22->SetGrid();
   c22->SaveAs("24_Layer4Edepratio.png");

   //
   //Step Length
   //

   TCanvas *c23 = new TCanvas("c23","c23",400,300);
   Layer1Steptank->SetLineColorAlpha(4, 0.35);
   Layer1Stepaway->SetLineColorAlpha(2, 0.35);
   Layer1Stepaway->Draw();
   L1Step->Draw("same hist");  
   c23->SetGrid();
   c23->SaveAs("25_Layer1Stepcompare.png");

   TCanvas *c24 = new TCanvas("c24","c24",400,300);
   Layer1Steptank->SetLineColorAlpha(4, 0.35);
   Layer1Steptank->Draw();
   Layer1Stepaway->Draw("same hist");
   Layer1Steptank->Divide(Layer1Stepaway);
   Layer1Steptank->Draw();
   c24->SetGrid();
   c24->SaveAs("26_Layer1Stepratio.png");

   TCanvas *c25 = new TCanvas("c25","c25",400,300);
   Layer2Steptank->SetLineColorAlpha(4, 0.35);
   Layer2Stepaway->SetLineColorAlpha(2, 0.35);
   Layer2Stepaway->Draw();
   L2Step->Draw("same hist");  
   c25->SetGrid();
   c25->SaveAs("27_Layer2Stepcompare.png");

   TCanvas *c26 = new TCanvas("c26","c26",400,300);
   Layer2Steptank->SetLineColorAlpha(4, 0.35);
   Layer2Steptank->Draw();
   Layer2Stepaway->Draw("same hist");
   Layer2Steptank->Divide(Layer2Stepaway);
   Layer2Steptank->Draw();
   c26->SetGrid();
   c26->SaveAs("28_Layer2Stepratio.png");

   TCanvas *c27 = new TCanvas("c27","c27",400,300);
   Layer3Steptank->SetLineColorAlpha(4, 0.35);
   Layer3Stepaway->SetLineColorAlpha(2, 0.35);
   Layer3Stepaway->Draw();
   L3Step->Draw("same hist");  
   c27->SetGrid();
   c27->SaveAs("29_Layer3Stepcompare.png");

   TCanvas *c28 = new TCanvas("c28","c28",400,300);
   Layer3Steptank->SetLineColorAlpha(4, 0.35);
   Layer3Steptank->Draw();
   Layer3Stepaway->Draw("same hist");
   Layer3Steptank->Divide(Layer3Stepaway);
   Layer3Steptank->Draw();
   c28->SetGrid();
   c28->SaveAs("30_Layer3Stepratio.png");

   TCanvas *c29 = new TCanvas("c29","c29",400,300);
   Layer4Steptank->SetLineColorAlpha(4, 0.35);
   Layer4Stepaway->SetLineColorAlpha(2, 0.35);
   Layer4Stepaway->Draw();
   L4Step->Draw("same hist");  
   c29->SetGrid();
   c29->SaveAs("31_Layer4Stepcompare.png");

   TCanvas *c30 = new TCanvas("c30","c30",400,300);
   Layer4Steptank->SetLineColorAlpha(4, 0.35);
   Layer4Steptank->Draw();
   Layer4Stepaway->Draw("same hist");
   Layer4Steptank->Divide(Layer4Stepaway);
   Layer4Steptank->Draw();
   c30->SetGrid();
   c30->SaveAs("32_Layer4Stepratio.png");

   //
   //Energy on par
   //

   TCanvas *c31 = new TCanvas("c31","c31",400,300);
   GenPtank->SetLineColorAlpha(4, 0.35);
   GenPaway->SetLineColorAlpha(2, 0.35);
   GenPaway->Draw();
   GPt->Draw("same hist");
   c31->SetGrid();
   c31->SaveAs("33_GenPcompare.png");

   TCanvas *c32 = new TCanvas("c32","c32",400,300);
   GenPtank->SetLineColorAlpha(4, 0.35);
   GenPtank->Draw();
   GenPaway->Draw("same hist");
   GenPtank->Divide(GenPaway);
   GenPtank->Draw();
   c32->SetGrid();
   c32->SaveAs("34_GenPratio.png");

   TCanvas *c33 = new TCanvas("c33","c33",400,300);
   EdepTestObjtank->Draw();
   c33->SaveAs("35_EdepTestObjratio.png");

   TCanvas *c34 = new TCanvas("c34","c34",400,300);
   StepTestObjtank->Draw();
   c34->SaveAs("36_StepTestObjratio.png");

   //
   //Z plane compare
   //
/*
   int nxzi=XYviewZPlaneaway->GetNbinsY();
   int nyzi=XYviewZPlaneaway->GetNbinsX();
   TH2D* XYviewZPlaneratio=new TH2D("XYviewZPlaneratio","Z plane XV View Ratio (True)",100,-50,50.0,100,-50.0,50.0);
     for (int ix=1; ix<=nxzi; ix++) {
      for(int iy=1; iy<=nyzi; iy++) {
         double wtA=XYviewZPlaneaway->GetBinContent(ix,iy);
         double wtT=XYviewZPlanetank->GetBinContent(ix,iy);
         double wt=wtT/wtA;
         if(wt>2.0) wt=2.0;
         double y=-51+iy;
         double x=-51+ix;
         XYviewZPlaneratio->Fill(x,y,wt);
        }
   }

   XYviewZPlaneratio->GetXaxis()->SetTitle("X (cm)");
   XYviewZPlaneratio->GetYaxis()->SetTitle("Y (cm)");

   int nxz5i=XYviewZPlane5cmaway->GetNbinsY();
   int nyz5i=XYviewZPlane5cmaway->GetNbinsX();
   TH2D* XYviewZPlaneratio5cm=new TH2D("XYviewZPlaneratio5cm","Z plane XV View Ratio (True) (5cm)",20,-50,50.0,20,-50.0,50.0);
     for (int ix=1; ix<=nxz5i; ix++) {
      for(int iy=1; iy<=nyz5i; iy++) {
         double wtA=XYviewZPlane5cmaway->GetBinContent(ix,iy);
         double wtT=XYviewZPlane5cmtank->GetBinContent(ix,iy);
         double wt=wtT/wtA;
         if(wt>2.0) wt=2.0;
         double y=-55+iy*5;
         double x=-55+ix*5;
         XYviewZPlaneratio5cm->Fill(x,y,wt);
        }
   }

   XYviewZPlaneratio5cm->GetXaxis()->SetTitle("X (cm)");
   XYviewZPlaneratio5cm->GetYaxis()->SetTitle("Y (cm)");

   TCanvas *c90 = new TCanvas("c90","c90",400,300);
   XYviewZPlaneratio->Draw("colz hist");
   c90->SaveAs("37_XYviewZPlaneratio.png");

   TCanvas *c91 = new TCanvas("c91","c91",400,300);
   XYviewZPlaneratio5cm->Draw("colz hist");
   c91->SaveAs("38_XYviewZPlaneratio5cm.png");

   TCanvas *c92 = new TCanvas("c92","c92",400,300);
   XviewZPlanetank->SetLineColorAlpha(4, 0.35);
   XviewZPlaneaway->SetLineColorAlpha(2, 0.35);
   XviewZPlaneaway->Draw();
   XPz->Draw("same hist");  
   c92->SetGrid();
   c92->SaveAs("39_XviewZPlanecompare.png");

   TCanvas *c93 = new TCanvas("c93","c93",400,300);
   XviewZPlanetank->SetLineColorAlpha(4, 0.35);
   XviewZPlanetank->Draw();
   XviewZPlaneaway->Draw("same hist");
   XviewZPlanetank->Divide(XviewZPlaneaway);
   XviewZPlanetank->Draw();
   c93->SetGrid();
   c93->SaveAs("40_XviewZPlaneratio.png");

   TCanvas *c94 = new TCanvas("c94","c94",400,300);
   YviewZPlanetank->SetLineColorAlpha(4, 0.35);
   YviewZPlaneaway->SetLineColorAlpha(2, 0.35);
   YviewZPlaneaway->Draw();
   YPz->Draw("same hist"); 
   c94->SetGrid(); 
   c94->SaveAs("41_YviewZPlanecompare.png");

   TCanvas *c95 = new TCanvas("c95","c95",400,300);
   YviewZPlanetank->SetLineColorAlpha(4, 0.35);
   YviewZPlanetank->Draw();
   YviewZPlaneaway->Draw("same hist");
   YviewZPlanetank->Divide(YviewZPlaneaway);
   YviewZPlanetank->Draw();
   c95->SetGrid();
   c95->SaveAs("42_YviewZPlaneratio.png");
*/
   //
   //5 Degree True Muon Angle Restriction
   //

   int nxTi=Tray1XY5degreeTaway->GetNbinsY();
   int nyTi=Tray1XY5degreeTaway->GetNbinsX();
   TH2D* Tray1XY5degreeTratio=new TH2D("Tray1XY5degreeTratio","Tray 1 XY View Ratio with 5 Degree Restriction (True)",60,-30,30.0,60,-30.0,30.0);
     for (int ix=1; ix<=nxTi; ix++) {
      for(int iy=1; iy<=nyTi; iy++) {
         double wtA=Tray1XY5degreeTaway->GetBinContent(ix,iy);
         double wtT=Tray1XY5degreeTtank->GetBinContent(ix,iy);
         double wt=wtT/wtA;
         if(wt>1.1) wt=1.1;
         if(wt<0.5) wt=0.5;
         double y=-31+iy;
         double x=-31+ix;
         Tray1XY5degreeTratio->Fill(x,y,wt);
        }
   }

   Tray1XY5degreeTratio->GetXaxis()->SetTitle("X (cm)");
   Tray1XY5degreeTratio->GetYaxis()->SetTitle("Y (cm)");
   //Tray1XY5degreeTratio->GetZaxis()->SetRangeUser(0.5, 1.5);

   int nxT5i=Tray1XY5degreeT5cmaway->GetNbinsY();
   int nyT5i=Tray1XY5degreeT5cmaway->GetNbinsX();
   TH2D* Tray1XY5degreeTratio5cm=new TH2D("Tray1XY5degreeTratio5cm","Tray 1 XY View Ratio with 5 Degree Restriction (True) (5cm)",12,-30,30.0,12,-30.0,30.0);
     for (int ix=1; ix<=nxT5i; ix++) {
      for(int iy=1; iy<=nyT5i; iy++) {
         double wtA=Tray1XY5degreeT5cmaway->GetBinContent(ix,iy);
         double wtT=Tray1XY5degreeT5cmtank->GetBinContent(ix,iy);
         double wt=wtT/wtA;
         if(wt>1.1) wt=1.1;
         if(wt<0.5) wt=0.5;
         double y=-35+iy*5;
         double x=-35+ix*5;
         Tray1XY5degreeTratio5cm->Fill(x,y,wt);
        }
   }

   Tray1XY5degreeTratio5cm->GetXaxis()->SetTitle("X (cm)");
   Tray1XY5degreeTratio5cm->GetYaxis()->SetTitle("Y (cm)");
   //Tray1XY5degreeTratio5cm->GetZaxis()->SetRangeUser(0.5, 1.5);

   TCanvas *c35 = new TCanvas("c35","c35",400,300);
   Tray1XY5degreeTratio->Draw("colz hist");
   c35->SaveAs("43_Tray1XY5degreeTratio.png");

   TCanvas *c36 = new TCanvas("c36","c36",400,300);
   Tray1XY5degreeTratio5cm->Draw("colz hist");
   c36->SaveAs("44_Tray1XY5degreeTratio5cm.png");

   TCanvas *c37 = new TCanvas("c37","c37",400,300);
   Tray1X5degreeTtank->SetLineColorAlpha(4, 0.35);
   Tray1X5degreeTaway->SetLineColorAlpha(2, 0.35);
   Tray1X5degreeTaway->Draw();
   X1T->Draw("same hist");  
   c37->SetGrid();
   c37->SaveAs("45_Tray1X5degreeTcompare.png");

   TCanvas *c38 = new TCanvas("c38","c38",400,300);
   Tray1X5degreeTtank->SetLineColorAlpha(4, 0.35);
   Tray1X5degreeTtank->Draw();
   Tray1X5degreeTaway->Draw("same hist");
   Tray1X5degreeTtank->Divide(Tray1X5degreeTaway);
   Tray1X5degreeTtank->Draw();
   c38->SetGrid();
   c38->SaveAs("46_Tray1X5degreeTratio.png");

   TCanvas *c39 = new TCanvas("c39","c39",400,300);
   Tray1Y5degreeTtank->SetLineColorAlpha(4, 0.35);
   Tray1Y5degreeTaway->SetLineColorAlpha(2, 0.35);
   Tray1Y5degreeTaway->Draw();
   Y1T->Draw("same hist");  
   c39->SetGrid();
   c39->SaveAs("47_Tray1Y5degreeTcompare.png");

   TCanvas *c40 = new TCanvas("c40","c40",400,300);
   Tray1Y5degreeTtank->SetLineColorAlpha(4, 0.35);
   Tray1Y5degreeTtank->Draw();
   Tray1Y5degreeTaway->Draw("same hist");
   Tray1Y5degreeTtank->Divide(Tray1Y5degreeTaway);
   Tray1Y5degreeTtank->Draw();
   c40->SetGrid();
   c40->SaveAs("48_Tray1Y5degreeTratio.png");

   TCanvas *c41 = new TCanvas("c41","c41",400,300);
   Tray2X5degreeTtank->SetLineColorAlpha(4, 0.35);
   Tray2X5degreeTaway->SetLineColorAlpha(2, 0.35);
   Tray2X5degreeTaway->Draw();
   X2T->Draw("same hist");  
   c41->SetGrid();
   c41->SaveAs("49_Tray2X5degreeTcompare.png");

   TCanvas *c42 = new TCanvas("c42","c42",400,300);
   Tray2X5degreeTtank->SetLineColorAlpha(4, 0.35);
   Tray2X5degreeTtank->Draw();
   Tray2X5degreeTaway->Draw("same hist");
   Tray2X5degreeTtank->Divide(Tray2X5degreeTaway);
   Tray2X5degreeTtank->Draw();
   c42->SetGrid();
   c42->SaveAs("50_Tray1X5degreeTratio.png");

   TCanvas *c43 = new TCanvas("c43","c34",400,300);
   Tray2Y5degreeTtank->SetLineColorAlpha(4, 0.35);
   Tray2Y5degreeTaway->SetLineColorAlpha(2, 0.35);
   Tray2Y5degreeTaway->Draw();
   Y2T->Draw("same hist");  
   c43->SetGrid();
   c43->SaveAs("51_Tray2Y5degreeTcompare.png");

   TCanvas *c44 = new TCanvas("c44","c44",400,300);
   Tray2Y5degreeTtank->SetLineColorAlpha(4, 0.35);
   Tray2Y5degreeTtank->Draw();
   Tray2Y5degreeTaway->Draw("same hist");
   Tray2Y5degreeTtank->Divide(Tray2Y5degreeTaway);
   Tray2Y5degreeTtank->Draw();
   c44->SetGrid();
   c44->SaveAs("52_Tray2Y5degreeTratio.png");

   //
   //5 Degree Reco Muon Angle Restriction
   //

   int nxTTi=Tray1XY5degreeTTaway->GetNbinsY();
   int nyTTi=Tray1XY5degreeTTaway->GetNbinsX();
   TH2D* Tray1XY5degreeTTratio=new TH2D("Tray1XY5degreeTTratio","Tray 1 XY View Ratio with 5 Degree Restriction (Track)",60,-30,30.0,60,-30.0,30.0);
     for (int ix=1; ix<=nxTi; ix++) {
      for(int iy=1; iy<=nyTi; iy++) {
         double wtA=Tray1XY5degreeTTaway->GetBinContent(ix,iy);
         double wtT=Tray1XY5degreeTTtank->GetBinContent(ix,iy);
         double wt=wtT/wtA;
         if(wt>1.1) wt=1.1;
         if(wt<0.5) wt=0.5;
         double y=-31+iy;
         double x=-31+ix;
         Tray1XY5degreeTTratio->Fill(x,y,wt);
        }
   }

   Tray1XY5degreeTTratio->GetXaxis()->SetTitle("X (cm)");
   Tray1XY5degreeTTratio->GetYaxis()->SetTitle("Y (cm)");
   //Tray1XY5degreeTTratio->GetZaxis()->SetRangeUser(0.5, 1.5);

   int nxTT5i=Tray1XY5degreeTT5cmaway->GetNbinsY();
   int nyTT5i=Tray1XY5degreeTT5cmaway->GetNbinsX();
   TH2D* Tray1XY5degreeTTratio5cm=new TH2D("Tray1XY5degreeTTratio5cm","Tray 1 XY View Ratio with 5 Degree Restriction (Track)",12,-30,30.0,12,-30.0,30.0);
     for (int ix=1; ix<=nxT5i; ix++) {
      for(int iy=1; iy<=nyT5i; iy++) {
         double wtA=Tray1XY5degreeTT5cmaway->GetBinContent(ix,iy);
         double wtT=Tray1XY5degreeTT5cmtank->GetBinContent(ix,iy);
         double wt=wtT/wtA;
         if(wt>1.1) wt=1.1;
         if(wt<0.5) wt=0.5;
         double y=-35+iy*5;
         double x=-35+ix*5;
         Tray1XY5degreeTTratio5cm->Fill(x,y,wt);
        }
   }

   Tray1XY5degreeTTratio5cm->GetXaxis()->SetTitle("X (cm)");
   Tray1XY5degreeTTratio5cm->GetYaxis()->SetTitle("Y (cm)");
   //Tray1XY5degreeTTratio5cm->GetZaxis()->SetRangeUser(0.5, 1.5);

   TCanvas *c45 = new TCanvas("c45","c45",400,300);
   Tray1XY5degreeTTratio->Draw("colz hist");
   c45->SaveAs("53_Tray1XY5degreeTTratio.png");

   TCanvas *c46 = new TCanvas("c46","c46",400,300);
   Tray1XY5degreeTTratio5cm->Draw("colz hist");
   c46->SaveAs("54_Tray1XY5degreeTTratio5cm.png");

   TCanvas *c47 = new TCanvas("c47","c47",400,300);
   Tray1X5degreeTTtank->SetLineColorAlpha(4, 0.35);
   Tray1X5degreeTTaway->SetLineColorAlpha(2, 0.35);
   Tray1X5degreeTTaway->Draw();
   X1TT->Draw("same hist");  
   c47->SetGrid();
   c47->SaveAs("55_Tray1X5degreeTTcompare.png");

   TCanvas *c48 = new TCanvas("c48","c48",400,300);
   Tray1X5degreeTTtank->SetLineColorAlpha(4, 0.35);
   Tray1X5degreeTTtank->Draw();
   Tray1X5degreeTTaway->Draw("same hist");
   Tray1X5degreeTTtank->Divide(Tray1X5degreeTTaway);
   Tray1X5degreeTTtank->Draw();
   c48->SetGrid();
   c48->SaveAs("56_Tray1X5degreeTTratio.png");

   TCanvas *c49 = new TCanvas("c49","c49",400,300);
   Tray1Y5degreeTTtank->SetLineColorAlpha(4, 0.35);
   Tray1Y5degreeTTaway->SetLineColorAlpha(2, 0.35);
   Tray1Y5degreeTTaway->Draw();
   Y1TT->Draw("same hist");  
   c49->SetGrid();
   c49->SaveAs("57_Tray1Y5degreeTTcompare.png");

   TCanvas *c50 = new TCanvas("c50","c50",400,300);
   Tray1Y5degreeTTtank->SetLineColorAlpha(4, 0.35);
   Tray1Y5degreeTTtank->Draw();
   Tray1Y5degreeTTaway->Draw("same hist");
   Tray1Y5degreeTTtank->Divide(Tray1Y5degreeTTaway);
   Tray1Y5degreeTTtank->Draw();
   c50->SetGrid();
   c50->SaveAs("58_Tray1Y5degreeTTratio.png");

   TCanvas *c51 = new TCanvas("c51","c51",400,300);
   Tray2X5degreeTTtank->SetLineColorAlpha(4, 0.35);
   Tray2X5degreeTTaway->SetLineColorAlpha(2, 0.35);
   Tray2X5degreeTTaway->Draw();
   X2T->Draw("same hist");  
   c51->SetGrid();
   c51->SaveAs("59_Tray2X5degreeTTcompare.png");

   TCanvas *c52 = new TCanvas("c52","c52",400,300);
   Tray2X5degreeTTtank->SetLineColorAlpha(4, 0.35);
   Tray2X5degreeTTtank->Draw();
   Tray2X5degreeTTaway->Draw("same hist");
   Tray2X5degreeTTtank->Divide(Tray2X5degreeTTaway);
   Tray2X5degreeTTtank->Draw();
   c52->SetGrid();
   c52->SaveAs("60_Tray1X5degreeTTratio.png");

   TCanvas *c53 = new TCanvas("c53","c54",400,300);
   Tray2Y5degreeTTtank->SetLineColorAlpha(4, 0.35);
   Tray2Y5degreeTTaway->SetLineColorAlpha(2, 0.35);
   Tray2Y5degreeTTaway->Draw();
   Y2TT->Draw("same hist");  
   c53->SetGrid();
   c53->SaveAs("61_Tray2Y5degreeTTcompare.png");

   TCanvas *c54 = new TCanvas("c54","c54",400,300);
   Tray2Y5degreeTTtank->SetLineColorAlpha(4, 0.35);
   Tray2Y5degreeTTtank->Draw();
   Tray2Y5degreeTTaway->Draw("same hist");
   Tray2Y5degreeTTtank->Divide(Tray2Y5degreeTTaway);
   Tray2Y5degreeTTtank->Draw();
   c54->SetGrid();
   c54->SaveAs("62_Tray2Y5degreeTTratio.png");

/*
   int nxzTi=XYviewZPlaneTaway->GetNbinsY();
   int nyzTi=XYviewZPlaneTaway->GetNbinsX();
   TH2D* XYviewZPlaneTratio=new TH2D("XYviewZPlaneTratio","Z plane XV View Ratio with 5 Degree Restriction (True)",100,-50,50.0,100,-50.0,50.0);
     for (int ix=1; ix<=nxzTi; ix++) {
      for(int iy=1; iy<=nyzTi; iy++) {
         double wtA=XYviewZPlaneTaway->GetBinContent(ix,iy);
         double wtT=XYviewZPlaneTtank->GetBinContent(ix,iy);
         double wt=wtT/wtA;
         if(wt>2.0) wt=2.0;
         double y=-51+iy;
         double x=-51+ix;
         XYviewZPlaneTratio->Fill(x,y,wt);
        }
   }

   XYviewZPlaneTratio->GetXaxis()->SetTitle("X (cm)");
   XYviewZPlaneTratio->GetYaxis()->SetTitle("Y (cm)");

   int nxz5Ti=XYviewZPlaneT5cmaway->GetNbinsY();
   int nyz5Ti=XYviewZPlaneT5cmaway->GetNbinsX();
   TH2D* XYviewZPlaneTratio5cm=new TH2D("XYviewZPlaneTratio5cm","Z plane XV View Ratio with 5 Degree Restriction (True) (5cm)",20,-50,50.0,20,-50.0,50.0);
     for (int ix=1; ix<=nxz5i; ix++) {
      for(int iy=1; iy<=nyz5i; iy++) {
         double wtA=XYviewZPlaneT5cmaway->GetBinContent(ix,iy);
         double wtT=XYviewZPlaneT5cmtank->GetBinContent(ix,iy);
         double wt=wtT/wtA;
         if(wt>2.0) wt=2.0;
         double y=-55+iy*5;
         double x=-55+ix*5;
         XYviewZPlaneTratio5cm->Fill(x,y,wt);
        }
   }

   XYviewZPlaneTratio5cm->GetXaxis()->SetTitle("X (cm)");
   XYviewZPlaneTratio5cm->GetYaxis()->SetTitle("Y (cm)");

   TCanvas *c55 = new TCanvas("c55","c55",400,300);
   XYviewZPlaneTratio->Draw("colz hist");
   c55->SaveAs("63_XYviewZPlaneTratio.png");

   TCanvas *c56 = new TCanvas("c56","c56",400,300);
   XYviewZPlaneTratio5cm->Draw("colz hist");
   c56->SaveAs("64_XYviewZPlaneTratio5cm.png");

   TCanvas *c57 = new TCanvas("c57","c57",400,300);
   XviewZPlaneTtank->SetLineColorAlpha(4, 0.35);
   XviewZPlaneTaway->SetLineColorAlpha(2, 0.35);
   XviewZPlaneTaway->Draw();
   XPzT->Draw("same hist");  
   c57->SaveAs("65_XviewZPlaneTcompare.png");

   TCanvas *c58 = new TCanvas("c58","c58",400,300);
   XviewZPlaneTtank->SetLineColorAlpha(4, 0.35);
   XviewZPlaneTtank->Draw();
   XviewZPlaneTaway->Draw("same hist");
   XviewZPlaneTtank->Divide(XviewZPlaneTaway);
   XviewZPlaneTtank->Draw();
   c58->SaveAs("66_XviewZPlaneTratio.png");

   TCanvas *c59 = new TCanvas("c59","c59",400,300);
   YviewZPlaneTtank->SetLineColorAlpha(4, 0.35);
   YviewZPlaneTaway->SetLineColorAlpha(2, 0.35);
   YviewZPlaneTaway->Draw();
   YPzT->Draw("same hist");  
   c59->SaveAs("67_YviewZPlaneTcompare.png");

   TCanvas *c60 = new TCanvas("c60","c60",400,300);
   YviewZPlaneTtank->SetLineColorAlpha(4, 0.35);
   YviewZPlaneTtank->Draw();
   YviewZPlaneTaway->Draw("same hist");
   YviewZPlaneTtank->Divide(YviewZPlaneTaway);
   YviewZPlaneTtank->Draw();
   c60->SaveAs("68_YviewZPlaneTratio.png");


   int nxzTTi=XYviewZPlaneTTaway->GetNbinsY();
   int nyzTTi=XYviewZPlaneTTaway->GetNbinsX();
   TH2D* XYviewZPlaneTTratio=new TH2D("XYviewZPlaneTTratio","Z plane XV View Ratio with 5 Degree Restriction (Track)",100,-50,50.0,100,-50.0,50.0);
     for (int ix=1; ix<=nxzTTi; ix++) {
      for(int iy=1; iy<=nyzTTi; iy++) {
         double wtA=XYviewZPlaneTTaway->GetBinContent(ix,iy);
         double wtT=XYviewZPlaneTTtank->GetBinContent(ix,iy);
         double wt=wtT/wtA;
         if(wt>2.0) wt=2.0;
         double y=-51+iy;
         double x=-51+ix;
         XYviewZPlaneTTratio->Fill(x,y,wt);
        }
   }

   XYviewZPlaneTTratio->GetXaxis()->SetTitle("X (cm)");
   XYviewZPlaneTTratio->GetYaxis()->SetTitle("Y (cm)");

   int nxz5TTi=XYviewZPlaneT5cmaway->GetNbinsY();
   int nyz5TTi=XYviewZPlaneT5cmaway->GetNbinsX();
   TH2D* XYviewZPlaneTTratio5cm=new TH2D("XYviewZPlaneTTratio5cm","Z plane XV View Ratio with 5 Degree Restriction (Track)",20,-50,50.0,20,-50.0,50.0);
     for (int ix=1; ix<=nxz5TTi; ix++) {
      for(int iy=1; iy<=nyz5TTi; iy++) {
         double wtA=XYviewZPlaneTT5cmaway->GetBinContent(ix,iy);
         double wtT=XYviewZPlaneTT5cmtank->GetBinContent(ix,iy);
         double wt=wtT/wtA;
         if(wt>2.0) wt=2.0;
         double y=-55+iy*5;
         double x=-55+ix*5;
         XYviewZPlaneTTratio5cm->Fill(x,y,wt);
        }
   }

   XYviewZPlaneTTratio5cm->GetXaxis()->SetTitle("X (cm)");
   XYviewZPlaneTTratio5cm->GetYaxis()->SetTitle("Y (cm)");

   TCanvas *c61 = new TCanvas("c61","c61",400,300);
   XYviewZPlaneTTratio->Draw("colz hist");
   c61->SaveAs("69_XYviewZPlaneTTratio.png");

   TCanvas *c62 = new TCanvas("c62","c62",400,300);
   XYviewZPlaneTTratio5cm->Draw("colz hist");
   c62->SaveAs("70_XYviewZPlaneTTratio5cm.png");

   TCanvas *c63 = new TCanvas("c63","c63",400,300);
   XviewZPlaneTTtank->SetLineColorAlpha(4, 0.35);
   XviewZPlaneTTaway->SetLineColorAlpha(2, 0.35);
   XviewZPlaneTTaway->Draw();
   XPzTT->Draw("same hist");  
   c63->SaveAs("71_XviewZPlaneTcompare.png");

   TCanvas *c64 = new TCanvas("c64","c64",400,300);
   XviewZPlaneTTtank->SetLineColorAlpha(4, 0.35);
   XviewZPlaneTTtank->Draw();
   XviewZPlaneTTaway->Draw("same hist");
   XviewZPlaneTTtank->Divide(XviewZPlaneTTaway);
   XviewZPlaneTTtank->Draw();
   c64->SaveAs("72_XviewZPlaneTTratio.png");

   TCanvas *c65 = new TCanvas("c65","c65",400,300);
   YviewZPlaneTTtank->SetLineColorAlpha(4, 0.35);
   YviewZPlaneTTaway->SetLineColorAlpha(2, 0.35);
   YviewZPlaneTTaway->Draw();
   YPzTT->Draw("same hist");  
   c65->SaveAs("73_YviewZPlaneTTcompare.png");

   TCanvas *c66 = new TCanvas("c66","c66",400,300);
   YviewZPlaneTTtank->SetLineColorAlpha(4, 0.35);
   YviewZPlaneTTtank->Draw();
   YviewZPlaneTTaway->Draw("same hist");
   YviewZPlaneTTtank->Divide(YviewZPlaneTTaway);
   YviewZPlaneTTtank->Draw();
   c66->SetGrid();
   c66->SaveAs("74_YviewZPlaneTTratio.png");
*/
   //
   // Reco z Plane
   //

   int nxzRi=xyZ15away->GetNbinsY();
   int nyzRi=xyZ15away->GetNbinsX();
   TH2D* xyZ15ratio=new TH2D("xyZ15ratio"," Reco Z plane XY View Ratio",15,-52.5,52.5,15,-52.5,52.5);
     for (int ix=1; ix<=nxzRi; ix++) {
      for(int iy=1; iy<=nyzRi; iy++) {
         double wtA=xyZ15away->GetBinContent(ix,iy);
         double wtT=xyZ15tank->GetBinContent(ix,iy);
         double wt=wtT/wtA;
         if(wt>1.2) wt=1.2;
         if(wt<0.5) wt=0.5;
         double y=-59.5+7*iy;
         double x=-59.5+7*ix;
         xyZ15ratio->Fill(x,y,wt);
        }
   }

   xyZ15ratio->GetXaxis()->SetTitle("X (cm)");
   xyZ15ratio->GetYaxis()->SetTitle("Y (cm)");
   //xyZ15ratio->GetZaxis()->SetRangeUser(0.8, 1.1);

   TCanvas *c67 = new TCanvas("c67","c67",400,300);
   xyZ15ratio->Draw("colz hist");
   c67->SaveAs("75_xyZ15ratio.png");
}