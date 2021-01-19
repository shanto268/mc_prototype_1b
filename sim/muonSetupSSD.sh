#!/bin/bash

#  setup SSD environment
export ROOTSYS="/Volumes/mac_extended/Research/MT/hep/root_v6.22.02"
export LD_LIBRARY_PATH="$ROOTSYS/lib:$LD_LIBRARY_PATH"
export PATH="$ROOTSYS/bin:$PATH"
export SSD_HEP="/Volumes/mac_extended/Research/MT/hep"
export CRYHOME=$SSD_HEP/cry/cry_v1.7
export CRYDATAPATH=$SSD_HEP/cry/cry_v1.7/data
export G4BASE=$SSD_HEP/g4/geant4.10.06.p01-install/source
export G4INSTALL=$SSD_HEP/g4/geant4.10.06.p01-install/share/Geant4-10.6.1/geant4make
export G4BIN="$PWD"

# set up ROOT and G4
source $ROOTSYS/bin/thisroot.sh
cd $SSD_HEP/g4/geant4.10.06.p01-install/bin/; source geant4.sh; cd $SSD_HEP

# aliases
alias ssim="mkdir build && cd build && cmake $G4BIN && make"
alias dsim="rm -rf build/"
alias sim="cmake $G4BIN && make"
alias isim="source $G4BIN/muonSetupMac.sh; cmake $G4BIN; make ;./exampleb4a"


#  drop_from_path taken from /root/build/bin/thisroot.sh
drop_from_path()
{
   # Assert that we got enough arguments
   if test $# -ne 2 ; then
      echo "drop_from_path: needs 2 arguments"
      return 1
   fi

   local p=$1
   local drop=$2

   newpath=`echo $p | sed -e "s;:${drop}:;:;g" \
                          -e "s;:${drop}\$;;g"   \
                          -e "s;^${drop}:;;g"   \
                          -e "s;^${drop}\$;;g"`
}

cd $SSD_HEP/g4/geant4.10.06.p01-install/share/Geant4-10.6.1/geant4make; source geant4make.sh; cd $G4BIN
