//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: B4aEventAction.cc 100946 2016-11-03 11:28:08Z gcosmo $
// 
/// \file B4aEventAction.cc
/// \brief Implementation of the B4aEventAction class

#include "B4aEventAction.hh"
#include "B4RunAction.hh"
#include "B4Analysis.hh"

#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4UnitsTable.hh"

#include "Randomize.hh"
#include <iomanip>

#include "MuonTree.h"
#include "SC8DataStruc.h"  // struct SC8edep


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4aEventAction::B4aEventAction()
 : G4UserEventAction(),
   edepSc8(),
   vecSC8Particle(),
   vecSC8HitsRef1(),
   vecSC8Hits1Tray(),
   vecSC8Hits2Tray(),
   vecSC8muontk(),
   muontree(0)
{
   
   _MuonXG4SeedA=1;
     char* _param4;
     _param4 = getenv("MuonXG4SeedA");
     if(_param4 != NULL) {_MuonXG4SeedA=atoi(_param4);}

   _MuonXG4SeedB=1;
     char* _param5;
     _param5 = getenv("CaloXG4SeedB");
     if(_param5 != NULL) {_MuonXG4SeedB=atoi(_param5);}

   
   if(_MuonXG4SeedA>0) {
      if(_MuonXG4SeedA==1) {
         long seeds[2];
         time_t systime = time(NULL);
         seeds[0] = (long) (systime+"1");
         seeds[1] = (long) (systime*G4UniformRand());
         G4Random::setTheSeeds(seeds);
         G4Random::showEngineStatus();
      }
      if(_MuonXG4SeedA>1) {
         long seeds[2];
         seeds[0] = (long) _MuonXG4SeedA;
         seeds[1] = (long) _MuonXG4SeedB;
         G4Random::setTheSeeds(seeds);
         G4Random::showEngineStatus();
      }
   }

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4aEventAction::~B4aEventAction()
{
   muontree.endjob();
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4aEventAction::BeginOfEventAction(const G4Event* /*event*/)
{  
  // initialization per event
  for(int i=0; i<40; i++) {
        edepSc8.SBAR[i]=0.0;
        edepSc8.MStepBar[i]=0.0; //changed by SAS 29/11
        }
  for(int i=0; i<4; i++) {
        edepSc8.TRAY[i]=0.0;
        edepSc8.MStepTray[i]=0.0; //changed by SAS 29/11
        }
  edepSc8.EdepTestObj = 0.0;
  edepSc8.StepTestObj = 0.0;
  vecSC8Particle.clear();
  vecSC8HitsRef1.clear();
  vecSC8Hits1Tray.clear();
  vecSC8Hits2Tray.clear();
  vecSC8muontk.clear(); 
//  edepSc8.mEdepWater=0.0;
//  edepSc8.mEdepWall=0.0;
//  edepSc8.mLengthWater=0.0;
//  edepSc8.mLengthWall=0.0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4aEventAction::EndOfEventAction(const G4Event* event)
{
  // std::cout<<"EndOfEventAction is called "<<std::endl;
  muontree.analyze(edepSc8,vecSC8Particle,vecSC8HitsRef1,vecSC8Hits1Tray,vecSC8Hits2Tray,vecSC8muontk);

}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
