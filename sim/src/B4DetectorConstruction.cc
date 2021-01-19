
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
// $Id: B4DetectorConstruction.cc 101905 2016-12-07 11:34:39Z gunter $
// 
/// \file B4DetectorConstruction.cc
/// \brief Implementation of the B4DetectorConstruction class

#include "B4DetectorConstruction.hh"

#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4Element.hh"
#include "G4ElementTable.hh"
#include "G4NistManager.hh"

#include "G4Box.hh"
#include "G4Sphere.hh" // included by rp for sphere
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"
#include "G4GlobalMagFieldMessenger.hh"
#include "G4AutoDelete.hh"

#include "G4GeometryManager.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4SolidStore.hh"
#include "G4SubtractionSolid.hh"
#include "G4UnionSolid.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"
#include "G4GDMLParser.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4ThreadLocal 
G4GlobalMagFieldMessenger* B4DetectorConstruction::fMagFieldMessenger = nullptr; 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4DetectorConstruction::B4DetectorConstruction()
 : G4VUserDetectorConstruction(),
   fCheckOverlaps(true)
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B4DetectorConstruction::~B4DetectorConstruction()
{ 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* B4DetectorConstruction::Construct()
{
  //GDML parser  
  G4GDMLParser fParser;  

  // Define materials 
  DefineMaterials();
  
  // Define volumes
  G4VPhysicalVolume* fWorldPhysVol = DefineVolumes();
  
  fParser.Write("proto1b.gdml", fWorldPhysVol);
  return fWorldPhysVol;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4DetectorConstruction::DefineMaterials()
{ 

  // Lead material defined using NIST Manager
  auto nistManager = G4NistManager::Instance();
  nistManager->FindOrBuildMaterial("G4_AIR");
  
  // Liquid argon material
  G4double a;  // mass of a mole;
  G4double z;  // z=mean number of protons;  
  G4double density;
  G4int ncomponents, natoms; 
  G4Element* C = new G4Element("Carbon", "C", z=6., a=12.01*g/mole);
  G4Element* H = new G4Element("Hydrogen", "H", z=1., a=1.01*g/mole);
  G4Element* Ca = new G4Element("Calcium", "Ca", z=20., a=40.078*g/mole);
  G4Element* O = new G4Element("Oxygen", "O", z=8., a=15.999*g/mole);
  new G4Material("liquidArgon", z=18., a= 39.95*g/mole, density= 1.390*g/cm3);
         // The argon by NIST Manager is a gas with a different density
  new G4Material("iron", z=26.,a=55.850*g/mole, density=7.894*g/cm3);
  new G4Material("tungsten", z=74.,a=183.85*g/mole, density=19.3*g/cm3);
  new G4Material("copper", z=29.,a=63.54*g/mole, density=8.96*g/cm3); 
  new G4Material("lead", z=82.,a=207.19*g/mole, density=11.34*g/cm3);
  // Vacuum
  new G4Material("Galactic", z=1., a=1.01*g/mole,density= universe_mean_density,
                  kStateGas, 2.73*kelvin, 3.e-18*pascal);

  G4Material* Scintillator = 
	new G4Material("Scintillator", density= 1.032*g/cm3, ncomponents=2);
	Scintillator->AddElement(C, natoms=9);
	Scintillator->AddElement(H, natoms=10);
	
	Scintillator->GetIonisation()->SetBirksConstant(0.126*mm/MeV);
  // Water
  G4Element* ele_H = new G4Element("Hydrogen","H",z=1.,a = 1.01*g/mole);
  G4Element* ele_O = new G4Element("Oxygen","O",z=8.,a=16.00*g/mole);
  G4Material* H2O = new G4Material("Water",density=1.000*g/cm3,ncomponents=2);
  H2O->AddElement(ele_H, natoms=2);
  H2O->AddElement(ele_O, natoms=1);

  //Limestone
  G4Material* Limestone =
	new G4Material("Limestone", density= 2.6*g/cm3, ncomponents=3);
	Limestone->AddElement(Ca, natoms=1);
	Limestone->AddElement(C, natoms=1);
	Limestone->AddElement(O, natoms=3);

  // Print materials
  G4cout << *(G4Material::GetMaterialTable()) << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* B4DetectorConstruction::DefineVolumes()
{
  /*  G4 Gerometry Tree
     World       (z: vertical (up: positive), x,y horizontal)
       - Tower
          - TankUnionLV(Sphere1S+MidTankS)
			- ftwaterLV(TnkWaterS - box)
          - Tube(Lower_pipe_cylinder)
	        - TubeWater
       - SC8     (xyz: similar to World)
           - Station    ( 1 copy for now) (xyz: similar to SC8)    
              - Tray    ( 4 copies)   (z: similar to Station, x along Bar's longer axis)
                  - sBar (Scintillator Bar)  (10 copies)  (z same as world, x along longer axis)
              - Ref1    (reference plane)
  */

  // Geometry parameters
  G4int nofBars = 10;
  G4double BarSizeX  = 60.*cm;
  G4double BarSizeY  = 5.*cm;
  G4double BarSizeZ  = 5.*cm;

  //G4double AirGap    = 0.1*cm;  // arond sBar.

  G4double TraySizeX  = BarSizeX;//+AirGap;
  G4double TraySizeY  = (BarSizeY/*+AirGap*/)*nofBars;//+AirGap;
  G4double TraySizeZ  = BarSizeZ;//+AirGap;
  G4double TrayPosX   = 0.0;
  G4double TrayPosY   = 0.0;
  G4double TrayPosZ[] = {593.73+256.7, 518.8+256.7, -518.8-256.7, -593.73-256.7};
  G4RotationMatrix* zRot = new G4RotationMatrix; // Rotates X and Z axes only
  zRot -> rotateX(0.*rad);
  zRot -> rotateY(0.*rad);
  zRot -> rotateZ(M_PI/2.*rad);

  // Get materials
  auto defaultMaterial = G4Material::GetMaterial("G4_AIR");
 // auto boxMaterial = G4Material::GetMaterial("iron");
 // auto boxMaterial = G4Material::GetMaterial("tungsten");
  //auto boxMaterial = G4Material::GetMaterial("copper");
  auto boxMaterial = G4Material::GetMaterial("lead");
  auto sBarMaterial  = G4Material::GetMaterial("Scintillator");
  if ( ! defaultMaterial || ! sBarMaterial ) {
    G4ExceptionDescription msg;
    msg << "Cannot retrieve materials already defined."; 
    G4Exception("B4DetectorConstruction::DefineVolumes()",
      "MyCode0001", FatalException, msg);
  }  
   
  //     
  // World
  //

  auto worldSizeX = 1000.0*cm ;  // half width
  auto worldSizeY = 1000.0*cm ;  // half width
  auto worldSizeZ = 1000.0*cm ;  // half width

  auto worldS 
    = new G4Box("World",           // its name
                 worldSizeX, worldSizeY, worldSizeZ); // its size
                         
  auto worldLV
    = new G4LogicalVolume(
                 worldS,           // its solid
                 defaultMaterial,  // its material
                 "World");         // its name
                                   
  auto worldPV
    = new G4PVPlacement(
                 0,                // no rotation
                 G4ThreeVector(),  // at (0,0,0)
                 worldLV,          // its logical volume                         
                 "World",          // its name
                 0,                // its mother  volume
                 false,            // no boolean operation
                 0,
                 fCheckOverlaps);		 // copy number

  
  //                               
  // SC8
  //  

  auto SC8SizeX= 150.*cm;  // a half width
  auto SC8SizeY= 150.*cm;  // a half width
  auto SC8SizeZ= TrayPosZ[0]+2.5*cm; // a half width

  auto SC8S
    = new G4Box("SC8",     // its name
                 SC8SizeX, SC8SizeY, SC8SizeZ); // its size
                         
  auto SC8LV
    = new G4LogicalVolume(
                 SC8S,     // its solid
                 defaultMaterial,  // its material
                 "SC8");   // its name
                                   
  new G4PVPlacement(
                 0,                // no rotation
                 G4ThreeVector(),  // at (0,0,0)
                 SC8LV,          // its logical volume                         
                 "SC8",    // its name
                 worldLV,          // its mother  volume
                 false,            // no boolean operation
                 0,                // copy number
                 fCheckOverlaps);  // checking overlaps 
  
  
  //                                 
  // Station
  //
  G4double StationSizeX  = 100.*cm;
  G4double StationSizeY  = 100.*cm;
  G4double StationSizeZ  = TrayPosZ[0]+2.5*cm;

  G4RotationMatrix* stationRot = new G4RotationMatrix; // Rotates X and Z axes only
double  angle=0.0*M_PI/180.0;   // no camera rotation.
  //std::cout<<"B4DetectorConstruction:  angle="<<angle<<std::endl;
  stationRot -> rotateX(0.*rad);
  stationRot -> rotateY(-angle*rad);
  stationRot -> rotateZ(0.*rad);

  auto Station1S
    = new G4Box("Station1",           // its name
                 StationSizeX, StationSizeY, StationSizeZ); // its size
                         
  auto Station1LV
    = new G4LogicalVolume(
                 Station1S,           // its solid
                 defaultMaterial,  // its material
                 "Station1");         // its name
   new G4PVPlacement(
                 stationRot,                // no rotation
                 G4ThreeVector(0,0,0),  // at (0,0,0)
                 Station1LV,          // its logical volume                         
                 "Station1",    // its name
                 SC8LV,          // its mother  volume
                 false,            // no boolean operation
                 0,                // copy number
                 fCheckOverlaps);  // checking overlaps

//   Reference Plane 1:  a thin horizontal plane at the center of station.

auto RefPlane1S
     = new G4Box("RefPlane1",           // its name
                 StationSizeX/2-1.0, StationSizeY/2-1.0, 1.0); // 
auto RefPlane1LV
    = new G4LogicalVolume(
                 RefPlane1S,        // its solid
                 defaultMaterial, // its material
                "RefPlane1");          // its name

   new G4PVPlacement(
                 0,                // no rotation
                 G4ThreeVector(0.0, 0.0, 0.0),  // at (0,0,0)
                 RefPlane1LV,          // its logical volume                         
                 "RefPlane1",    // its name
                 Station1LV,          // its mother  volume
                 false,            // no boolean operation
                 0,                // copy number
                 fCheckOverlaps);  // checking overlaps
   
   
   
   auto TrayPlane1S
      = new G4Box("TrayPlane1",
	         30.0*cm,30.0*cm,1*mm);
   
   auto TrayPlane1LV
    = new G4LogicalVolume(
                 TrayPlane1S,        // its solid
                 defaultMaterial, // its material
                "TrayPlane1");          // its name

   new G4PVPlacement(
                 0,                // no rotation
                 G4ThreeVector(0.0, 0.0, (TrayPosZ[0]+TrayPosZ[1])/2),  // at (0,0,0)
                 TrayPlane1LV,          // its logical volume
                 "TrayPlane1",    // its name
                 Station1LV,          // its mother  volume
                 false,            // no boolean operation
                 0,                // copy number
                 fCheckOverlaps);  // checking overlaps


  
  auto TrayPlane2S
      = new G4Box("TrayPlane2",
	         30.0*cm,30.0*cm,1*mm);
   
   auto TrayPlane2LV
    = new G4LogicalVolume(
                 TrayPlane2S,        // its solid
                 defaultMaterial, // its material
                "TrayPlane2");          // its name

   new G4PVPlacement(
                 0,                // no rotation
                 G4ThreeVector(0.0, 0.0, (TrayPosZ[2]+TrayPosZ[3])/2),  // at (0,0,0)
                 TrayPlane2LV,          // its logical volume
                 "TrayPlane2",    // its name
                 Station1LV,          // its mother  volume
                 false,            // no boolean operation
                 0,                // copy number
                 fCheckOverlaps);  // checking overlaps



   //    Four trays, containing 10 sintillation bars...
   auto Tray1S
     = new G4Box("Tray1",           // its name
                  TraySizeX/2, TraySizeY/2, TraySizeZ/2); // its size  
   auto Tray1LV
    = new G4LogicalVolume(
                 Tray1S,        // its solid
                 defaultMaterial, // its material
                "Tray1");          // its name

   new G4PVPlacement(              
                 0,                // no rotation
                 G4ThreeVector(TrayPosX,TrayPosY,TrayPosZ[0]),  // at (0,0,0)
                 Tray1LV,          // its logical volume                         
                 "Tray1",    // its name
                 Station1LV,          // its mother  volume
                 false,            // no boolean operation
                 0,                // copy number
                 fCheckOverlaps);  // checking overlaps

   new G4PVPlacement(
                 zRot,                // no rotation
                 G4ThreeVector(TrayPosX,TrayPosY,TrayPosZ[1]),  // at (0,0,0)
                 Tray1LV,          // its logical volume                         
                 "Tray1",    // its name
                 Station1LV,          // its mother  volume
                 false,            // no boolean operation
                 1,                // copy number
                 fCheckOverlaps);  // checking overlaps

   new G4PVPlacement(
                 0,                // no rotation
                 G4ThreeVector(TrayPosX,TrayPosY,TrayPosZ[2]),  // at (0,0,0)
                 Tray1LV,          // its logical volume                         
                 "Tray1",    // its name
                 Station1LV,          // its mother  volume
                 false,            // no boolean operation
                 2,                // copy number
                 fCheckOverlaps);  // checking overlaps

   new G4PVPlacement(
                 zRot,                // no rotation
                 G4ThreeVector(TrayPosX,TrayPosY,TrayPosZ[3]),  // at (0,0,0)
                 Tray1LV,          // its logical volume                         
                 "Tray1",    // its name
                 Station1LV,          // its mother  volume
                 false,            // no boolean operation
                 3,                // copy number
                 fCheckOverlaps);  // checking overlaps
  std::cout<<"B4DetectorConstruction:  TrayPosZ2= "<<TrayPosZ[2]<<std::endl;
  std::cout<<"B4DetectorConstruction:  TrayPosZ3= "<<TrayPosZ[3]<<std::endl;

  //                               
  // Individual bar
  //
  auto sBARS
    = new G4Box("sBAR",             // its name
                 BarSizeX/2.0, BarSizeY/2.0, BarSizeZ/2.0); // its size
                         
  auto sBARLV
    = new G4LogicalVolume(
                 sBARS,             // its solid
                 sBarMaterial,      // its material
                 "sBAR");           // its name

  for (int i=0; i<nofBars; i++) {
    double yval=-TraySizeY/2+BarSizeY/2.0/*+AirGap*/+(BarSizeY/*+AirGap*/)*float(i);
   // std::cout<<"  i  "<<i<<" yval "<<yval<<std::endl;                    
    new G4PVPlacement(
                 0,                // no rotation
                 G4ThreeVector(0.0,yval,0.0), // its position
                 sBARLV,            // its logical volume                         
                 "sBAR",            // its name
                 Tray1LV,          // its mother  volume
                 false,            // no boolean operation
                 i,                // copy number
                 fCheckOverlaps);  // checking overlaps 
  }
  std::cout<<"B4DetectorCOnstruction: nofBars="<<nofBars<<std::endl;

    //
    // Lead Box
    //
    
    G4double BoxSizeX = 20.32*cm; //5.08*4*cm;
    G4double BoxSizeY = 2*10.16*cm; //10.16*cm;
    G4double BoxSizeZ = 4*5.08*cm; //(20.32+(4*5.08))*cm;
    
    auto TestObjS
        = new G4Box("TestObj", //its name
                BoxSizeX/2, BoxSizeY/2, BoxSizeZ/2); // its size

    auto TestObjLV
        = new G4LogicalVolume(
                TestObjS,
                boxMaterial,
                "TestObj");

    new G4PVPlacement(
            0,
            G4ThreeVector(0.0,0.0,TrayPosZ[0]+2.5*cm+50.8*cm+BoxSizeZ/2),
            TestObjLV,
            "TestObj",
            worldLV,
            false,
            0,
            fCheckOverlaps);
/*
G4RotationMatrix* brickRot = new G4RotationMatrix; // Rotates X and Z axes only
double  bangle=90.0*M_PI/180.0;   // no camera rotation.
  brickRot -> rotateZ(bangle*rad);

    auto TestObj1S
        = new G4Box("TestObj1", //its name
                BoxSizeX/2, BoxSizeY/2, BoxSizeZ/2); // its size


    auto TestObj1LV
        = new G4LogicalVolume(
                TestObj1S,
                boxMaterial,
                "TestObj1");

    new G4PVPlacement(
            brickRot,
            G4ThreeVector(0.0,0.0+BoxSizeY/2+BoxSizeX/2,TrayPosZ[0]+2.5*cm+50.8*cm+BoxSizeZ/2),
            TestObjLV,
            "TestObj1",
            worldLV,
            false,
            0,
            fCheckOverlaps); */
            
   

  //
  // print parameters
  //
  G4cout
    << G4endl 
    << "------------------------------------------------------------" << G4endl
    << "---> The calorimeter is " << nofBars << " bars of: [ "
    << BarSizeX/cm << "mm of " << sBarMaterial->GetName() << " ] " << G4endl
    << "------------------------------------------------------------" << G4endl;
  
  //                                       
  // Visualization attributes
  //

  worldLV->SetVisAttributes(new G4VisAttributes(TRUE,G4Colour(0.0,0.0,1.0))); // blue
  SC8LV->SetVisAttributes(new G4VisAttributes(TRUE,G4Colour(0.45,0.25,0.0))); 
  Station1LV->SetVisAttributes(new G4VisAttributes(TRUE,G4Colour(0.0,1.0,0.0)));
  Tray1LV->SetVisAttributes(new G4VisAttributes(TRUE,G4Colour(0.0,0.0,0.0)));
  sBARLV->SetVisAttributes(new G4VisAttributes(TRUE,G4Colour(1.0,0.0,0.0)));
  TestObjLV->SetVisAttributes(new G4VisAttributes(TRUE,G4Colour(0.345098, 0.407843, 0.121569, 0.30)));
  //TestObj1LV->SetVisAttributes(new G4VisAttributes(TRUE,G4Colour(0.345098, 0.407843, 0.121569, 0.30)));
  TrayPlane1LV->SetVisAttributes(new G4VisAttributes(TRUE,G4Colour(0.345098, 0.407843, 0.121569, 0.30)));
  TrayPlane2LV->SetVisAttributes(new G4VisAttributes(TRUE,G4Colour(0.345098, 0.407843, 0.121569, 0.30)));
 // SolLV->SetVisAttributes(new G4VisAttributes(TRUE,G4Colour(0.345098, 0.407843, 0.121569, 0.30)));
  //
  // Always return the physical World
  //
  return worldPV;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B4DetectorConstruction::ConstructSDandField()
{ 
  // Create global magnetic field messenger.
  // Uniform magnetic field is then created automatically if
  // the field value is not zero.
  G4ThreeVector fieldValue;
  fMagFieldMessenger = new G4GlobalMagFieldMessenger(fieldValue);
  fMagFieldMessenger->SetVerboseLevel(1);
  
  // Register the field messenger for deleting
  G4AutoDelete::Register(fMagFieldMessenger);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
