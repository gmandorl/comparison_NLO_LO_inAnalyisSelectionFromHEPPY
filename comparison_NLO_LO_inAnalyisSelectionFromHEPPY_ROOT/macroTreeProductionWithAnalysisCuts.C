#include <stdio.h>
#include <iostream>


#include "TTree.h"
#include <TVector3.h>
#include <TLorentzVector.h>

#include <ctype.h>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include "TFile.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH2.h"
#include "TTree.h"
#include "TChain.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm> 
#include <TROOT.h>
#include <TString.h>
#include <TStyle.h>
#include <TSystem.h>
#include <TCanvas.h>
#include <TMarker.h>
#include <THStack.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TCut.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TLorentzVector.h>
#include <TMath.h>
#include <TF1.h>
#include <TProfile.h>
#include "math.h"







void macroTreeProductionWithAnalysisCuts () {


        std::cout<<"==================================================================================== INITIAL_FILE \t"<<std::endl;
        
        
        std::string name = "Inclusive_NLO";
//         name = "Inclusive_LO";
         name = "highMass_NLO";
//         name = "highMass_LO";
//         
//         name = "Data";
        
        
        TString nameOutputSample= "testfromHEPPY_"+name;
//         TString nameOutputSample= "testfromSKIM_"+name;
        TString pathName="";
        std::vector<TString> sampleNames;
        
        if(name.find("highMass_LO")!=std::string::npos) {
         pathName= "/gpfs/ddn/srm/cms/store/user/arizzi/VHBBHeppyV27d/DYJetsToLL_M-105To160_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/VH_V27d_DYJetsToLL_M-105To160_TuneCUETP8M1_13TeV-madgraphMLM-Py8__RunIISummer16MAv2-PUMoriond17_80r2as_2016_TrancheIV_v6-v1/171213_075003/0000/";
         sampleNames= {"tree_800.root"};
//         sampleNames= {"tree_6.root", "tree_7.root", "tree_748.root", "tree_754.root", "tree_760.root", "tree_767.root", "tree_773.root", "tree_799.root", "tree_805.root", "tree_811.root", "tree_743.root", "tree_749.root", "tree_755.root", "tree_761.root", "tree_768.root", "tree_774.root", "tree_8.root", "tree_806.root", "tree_9.root", "tree_744.root", "tree_750.root", "tree_756.root", "tree_762.root", "tree_769.root", "tree_775.root", "tree_800.root", "tree_807.root", "tree_745.root", "tree_751.root", "tree_757.root", "tree_763.root", "tree_770.root", "tree_796.root", "tree_801.root", "tree_808.root", "tree_746.root", "tree_752.root",  "tree_758.root",  "tree_764.root", "tree_771.root", "tree_797.root",  "tree_802.root",  "tree_809.root", "tree_6.root", "tree_747.root", "tree_753.root",  "tree_759.root",  "tree_766.root",  "tree_772.root",  "tree_798.root",  "tree_803.root",  "tree_810.root"};
//         
//         
        
        
//        pathName = "/afs/cern.ch/work/g/gimandor/public/Hmumu_nTuples/";
//        sampleNames = {"DYJetsToLL_M-105To160-madgraphMLM_v25_reskim.root"};
//         
        }
        
        
        if(name.find("highMass_NLO")!=std::string::npos) {
         pathName= "/gpfs/ddn/srm/cms/store/user/arizzi/VHBBHeppyV27d/DYJetsToLL_M-105To160_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/VH_V27d_DYJetsToLL_M-105To160_TuneCUETP8M1_13TeV-amcatnloFXFX-Py8__RunIISummer16MAv2-PUMoriond17_80r2as_2016_TrancheIV_v6-v2/180213_121503/0000/";
       sampleNames= {"tree_800.root"};
//           sampleNames= {"tree_6.root", "tree_10.root", "tree_100.root", "tree_101.root", "tree_102.root", "tree_103.root", "tree_104.root", "tree_105.root", "tree_106.root", "tree_107.root", "tree_108.root", "tree_109.root", "tree_110.root", "tree_111.root", "tree_112.root", "tree_113.root", "tree_114.root", "tree_116.root", "tree_117.root", "tree_118.root", "tree_119.root"};
// // //         sampleNames= {"tree_6.root", "tree_10.root", "tree_100.root", "tree_101.root"};
// //         sampleNames= {"tree_6.root", "tree_10.root", "tree_100.root", "tree_101.root", "tree_102.root", "tree_103.root", "tree_104.root", "tree_105.root", "tree_106.root", "tree_107.root", "tree_108.root", "tree_109.root", "tree_110.root", "tree_111.root", "tree_112.root", "tree_113.root", "tree_114.root", "tree_116.root", "tree_117.root", "tree_118.root", "tree_119.root"};
//          sampleNames= {"tree_6.root", "tree_10.root", "tree_100.root", "tree_101.root", "tree_102.root", "tree_103.root", "tree_104.root", "tree_105.root", "tree_106.root", "tree_107.root", "tree_108.root", "tree_109.root", "tree_110.root", "tree_111.root", "tree_112.root", "tree_113.root", "tree_114.root", "tree_116.root", "tree_117.root", "tree_118.root", "tree_119.root", "tree_176.root", "tree_270.root", "tree_357.root", "tree_450.root", "tree_535.root", "tree_621.root", "tree_704.root", "tree_794.root", "tree_891.root", "tree_99.root", "tree_177.root", "tree_271.root", "tree_358.root", "tree_451.root", "tree_536.root", "tree_622.root", "tree_705.root", "tree_795.root", "tree_892.root", "tree_990.root", "tree_178.root", "tree_273.root", "tree_359.root", "tree_452.root", "tree_537.root", "tree_623.root", "tree_706.root", "tree_796.root", "tree_893.root", "tree_991.root", "tree_179.root", "tree_274.root", "tree_36.root", "tree_453.root", "tree_538.root", "tree_624.root", "tree_707.root", "tree_797.root", "tree_895.root", "tree_993.root", "tree_18.root", "tree_275.root", "tree_360.root", "tree_454.root", "tree_539.root", "tree_625.root", "tree_708.root", "tree_798.root", "tree_896.root", "tree_994.root", "tree_180.root", "tree_276.root", "tree_361.root", "tree_455.root", "tree_54.root", "tree_626.root", "tree_709.root", "tree_799.root", "tree_897.root", "tree_995.root", "tree_181.root", "tree_277.root", "tree_363.root", "tree_456.root", "tree_540.root", "tree_627.root", "tree_71.root", "tree_8.root", "tree_898.root", "tree_997.root", "tree_182.root", "tree_278.root", "tree_364.root", "tree_457.root", "tree_541.root", "tree_628.root", "tree_710.root", "tree_80.root", "tree_899.root", "tree_999.root", "tree_183.root", "tree_279.root", "tree_365.root", "tree_458.root", "tree_542.root", "tree_629.root", "tree_711.root", "tree_800.root", "tree_9.root", "tree_184.root", "tree_28.root", "tree_366.root", "tree_459.root", "tree_543.root", "tree_63.root", "tree_712.root", "tree_801.root", "tree_90.root", "tree_185.root", "tree_280.root", "tree_367.root", "tree_460.root", "tree_544.root", "tree_630.root", "tree_713.root", "tree_802.root", "tree_900.root"};
        
        
        
//        pathName = "/afs/cern.ch/work/g/gimandor/public/Hmumu_nTuples/";
//        sampleNames = {"DYJetstoLL_amc_Filter105_v25_reskim.root"};
//         sampleNames = {"DYJetsToLL_M-105To160-amcatnloFXFX_v25_reskim.root"};

        }
        
        
        if(name.find("Inclusive_LO")!=std::string::npos) {
        pathName= "/gpfs/ddn/srm/cms/store/user/arizzi/VHBBHeppyV25b/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/VHHe_V25giulio_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-Py8__RunIISummer16MAv2-PUMoriond17_80r2as_2016_TrancheIV_v6_ext1-v2/170713_150149/0000/";
        sampleNames= {"tree_10.root"};
//        sampleNames= {"tree_10.root", "tree_18.root", "tree_20.root", "tree_3.root", "tree_5.root", "tree_7.root", "tree_9.root", "tree_1.root", "tree_13.root", "tree_2.root", "tree_21.root", "tree_4.root", "tree_6.root", "tree_8.root"};
                
        
//         NON USARE
//         pathName= "/gpfs/ddn/srm/cms/store/user/arizzi/VHBBHeppyV25b/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/VHBB_HEPPY_V25b_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-madgraphMLM-Py8__RunIISummer16MAv2-PUMoriond17_80r2as_2016_TrancheIV_v6_ext2-v1/170310_161315/0000/";
//         sampleNames= {"tree_188.root", "tree_289.root", "tree_39.root", "tree_490.root", "tree_591.root", "tree_692.root", "tree_793.root", "tree_894.root", "tree_995.root", "tree_189.root", "tree_29.root", "tree_390.root", "tree_491.root", "tree_592.root", "tree_693.root", "tree_794.root", "tree_895.root", "tree_996.root", "tree_19.root", "tree_290.root", "tree_391.root", "tree_492.root", "tree_593.root", "tree_694.root", "tree_795.root", "tree_896.root", "tree_997.root", "tree_190.root", "tree_291.root", "tree_392.root", "tree_493.root", "tree_594.root", "tree_695.root", "tree_796.root", "tree_897.root", "tree_998.root", "tree_191.root", "tree_292.root", "tree_393.root", "tree_494.root", "tree_595.root", "tree_696.root", "tree_797.root", "tree_898.root", "tree_999.root", "tree_192.root", "tree_293.root", "tree_394.root", "tree_495.root", "tree_596.root", "tree_697.root", "tree_798.root", "tree_899.root", "tree_193.root", "tree_294.root", "tree_395.root", "tree_496.root", "tree_597.root", "tree_698.root", "tree_799.root", "tree_9.root", "tree_194.root", "tree_295.root", "tree_396.root", "tree_497.root", "tree_598.root", "tree_699.root", "tree_8.root", "tree_90.root", "tree_195.root", "tree_296.root", "tree_397.root", "tree_498.root", "tree_599.root", "tree_7.root", "tree_80.root", "tree_900.root", "tree_196.root", "tree_297.root", "tree_398.root", "tree_499.root", "tree_6.root", "tree_70.root", "tree_800.root", "tree_901.root", "tree_197.root", "tree_298.root", "tree_399.root", "tree_5.root", "tree_60.root", "tree_700.root", "tree_801.root", "tree_902.root", "tree_198.root", "tree_299.root", "tree_4.root", "tree_50.root", "tree_600.root", "tree_701.root", "tree_802.root", "tree_903.root", "tree_199.root", "tree_3.root", "tree_40.root", "tree_500.root", "tree_601.root", "tree_702.root", "tree_803.root", "tree_904.root"};

                
        }
        
        
        if(name.find("Inclusive_NLO")!=std::string::npos) {
        pathName= "/gpfs/ddn/srm/cms/store/user/arizzi/VHBBHeppyV27a/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/VH_V27a_DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-Py8__RunIISummer16MAv2-PUMoriond17_80r2as_2016_TrancheIV_v6_ext2-v1/171127_091446/0000/";
//         sampleNames= {"tree_19.root", "tree_286.root", "tree_383.root", "tree_482.root", "tree_580.root", "tree_68.root", "tree_782.root", "tree_887.root", "tree_190.root", "tree_287.root"};
//         sampleNames= {"tree_19.root", "tree_286.root", "tree_383.root", "tree_482.root", "tree_580.root", "tree_68.root", "tree_782.root", "tree_887.root", "tree_190.root", "tree_287.root", "tree_384.root", "tree_483.root", "tree_581.root", "tree_680.root", "tree_783.root", "tree_888.root", "tree_191.root", "tree_288.root", "tree_385.root", "tree_484.root", "tree_582.root", "tree_681.root", "tree_784.root", "tree_89.root", "tree_192.root", "tree_289.root", "tree_386.root", "tree_485.root", "tree_583.root", "tree_682.root", "tree_785.root", "tree_890.root", "tree_193.root", "tree_29.root", "tree_387.root", "tree_486.root", "tree_584.root", "tree_683.root", "tree_786.root", "tree_891.root", "tree_194.root", "tree_290.root", "tree_388.root", "tree_487.root", "tree_585.root", "tree_684.root", "tree_787.root", "tree_894.root", "tree_195.root", "tree_291.root", "tree_389.root", "tree_488.root", "tree_586.root", "tree_685.root", "tree_788.root", "tree_895.root"};
        sampleNames= {"tree_19.root", "tree_286.root", "tree_383.root", "tree_482.root", "tree_580.root", "tree_68.root", "tree_782.root", "tree_887.root", "tree_190.root", "tree_287.root", "tree_384.root", "tree_483.root", "tree_581.root", "tree_680.root", "tree_783.root", "tree_888.root", "tree_191.root", "tree_288.root", "tree_385.root", "tree_484.root", "tree_582.root", "tree_681.root", "tree_784.root", "tree_89.root", "tree_192.root", "tree_289.root", "tree_386.root", "tree_485.root", "tree_583.root", "tree_682.root", "tree_785.root", "tree_890.root", "tree_193.root", "tree_29.root", "tree_387.root", "tree_486.root", "tree_584.root", "tree_683.root", "tree_786.root", "tree_891.root", "tree_194.root", "tree_290.root", "tree_388.root", "tree_487.root", "tree_585.root", "tree_684.root", "tree_787.root", "tree_894.root", "tree_195.root", "tree_291.root", "tree_389.root", "tree_488.root", "tree_586.root", "tree_685.root", "tree_788.root", "tree_895.root", "tree_18.root", "tree_277.root", "tree_374.root", "tree_473.root", "tree_571.root", "tree_67.root", "tree_773.root", "tree_877.root", "tree_989.root", "tree_180.root", "tree_278.root", "tree_375.root", "tree_474.root", "tree_572.root", "tree_670.root", "tree_774.root", "tree_878.root", "tree_99.root", "tree_181.root", "tree_279.root", "tree_376.root", "tree_475.root", "tree_573.root", "tree_671.root", "tree_775.root", "tree_879.root", "tree_990.root", "tree_182.root", "tree_28.root", "tree_377.root", "tree_476.root", "tree_574.root", "tree_672.root", "tree_776.root", "tree_88.root", "tree_991.root", "tree_183.root", "tree_280.root", "tree_378.root", "tree_477.root", "tree_575.root", "tree_673.root", "tree_777.root", "tree_880.root", "tree_992.root", "tree_184.root", "tree_281.root", "tree_379.root", "tree_478.root", "tree_576.root", "tree_675.root", "tree_778.root", "tree_881.root", "tree_993.root", "tree_185.root", "tree_282.root", "tree_38.root", "tree_479.root", "tree_577.root", "tree_676.root", "tree_779.root", "tree_882.root", "tree_995.root", "tree_186.root", "tree_283.root", "tree_380.root", "tree_48.root", "tree_578.root", "tree_677.root", "tree_78.root", "tree_883.root", "tree_996.root", "tree_187.root", "tree_284.root", "tree_381.root", "tree_480.root", "tree_579.root", "tree_678.root", "tree_780.root", "tree_884.root", "tree_998.root", "tree_189.root", "tree_285.root", "tree_382.root", "tree_481.root", "tree_58.root", "tree_679.root", "tree_781.root", "tree_886.root", "tree_999.root"};
        }
    

    

    
    

        
        if(name.find("Data")!=std::string::npos) {
//         pathName= "/gpfs/ddn/srm/cms/store/user/arizzi/VHBBHeppyV25/SingleMuon/VHBB_HEPPY_V25_SingleMuon__Run2016B-23Sep2016-v1/170130_115425/0000/";
//         sampleNames= {"tree_106.root", "tree_127.root", "tree_148.root", "tree_169.root", "tree_19.root", "tree_21.root", "tree_31.root", "tree_52.root", "tree_73.root"};
//         sampleNames= {"tree_106.root", "tree_127.root", "tree_148.root", "tree_169.root", "tree_19.root", "tree_21.root", "tree_31.root", "tree_52.root", "tree_73.root", "tree_94.root", "tree_10.root", "tree_120.root", "tree_141.root", "tree_162.root", "tree_183.root", "tree_203.root", "tree_25.root", "tree_46.root", "tree_67.root", "tree_88.root", "tree_100.root", "tree_121.root", "tree_142.root", "tree_163.root", "tree_184.root", "tree_204.root", "tree_26.root", "tree_47.root", "tree_68.root", "tree_89.root", "tree_101.root", "tree_122.root", "tree_143.root", "tree_164.root", "tree_185.root", "tree_205.root", "tree_27.root", "tree_48.root", "tree_69.root", "tree_9.root", "tree_102.root", "tree_123.root", "tree_144.root", "tree_165.root", "tree_186.root", "tree_206.root", "tree_28.root", "tree_49.root", "tree_7.root", "tree_90.root", "tree_103.root", "tree_124.root", "tree_145.root", "tree_166.root", "tree_187.root", "tree_207.root", "tree_29.root", "tree_5.root", "tree_70.root", "tree_91.root", "tree_104.root", "tree_125.root", "tree_146.root", "tree_167.root", "tree_188.root", "tree_208.root", "tree_3.root", "tree_50.root", "tree_71.root", "tree_92.root", "tree_105.root", "tree_126.root", "tree_147.root", "tree_168.root", "tree_189.root", "tree_209.root", "tree_30.root", "tree_51.root", "tree_72.root", "tree_93.root", "tree_107.root", "tree_128.root", "tree_149.root", "tree_17.root", "tree_190.root", "tree_210.root", "tree_32.root", "tree_53.root", "tree_74.root", "tree_95.root", "tree_108.root", "tree_129.root", "tree_15.root", "tree_170.root", "tree_191.root", "tree_211.root", "tree_33.root", "tree_54.root", "tree_75.root", "tree_96.root", "tree_109.root", "tree_13.root", "tree_150.root", "tree_171.root", "tree_192.root", "tree_212.root", "tree_34.root", "tree_55.root", "tree_76.root", "tree_97.root", "tree_11.root", "tree_130.root", "tree_151.root", "tree_172.root", "tree_193.root", "tree_213.root", "tree_35.root", "tree_56.root", "tree_77.root", "tree_98.root", "tree_110.root", "tree_131.root", "tree_152.root", "tree_173.root", "tree_194.root", "tree_214.root", "tree_36.root", "tree_57.root", "tree_78.root", "tree_99.root"};
        
        
        
        pathName = "/afs/cern.ch/work/g/gimandor/public/Hmumu_nTuples/";
        sampleNames = {"SingleMuon_reminiaod_v25.root"};
        }


        TH1F* countPos;
        TH1F* countNeg;
        TH1F* countWeighted;
         
           

//         TChain * tree_initial = (TChain*)file_initial->Get("tree");
        
        TChain * tree_initial = new TChain("tree");
        for(int n=0; n<sampleNames.size();n++) {
            tree_initial->Add(pathName + sampleNames[n]);
            TFile * file_initial = new TFile (pathName + sampleNames[n]);
            
            if (n==0) {
                countPos = (TH1F*)((TH1F*)file_initial->Get("CountPosWeight"))->Clone("CountPosWeight");
                countNeg = (TH1F*)((TH1F*)file_initial->Get("CountNegWeight"))->Clone("CountNegWeight");
                countWeighted = (TH1F*)((TH1F*)file_initial->Get("CountWeighted"))->Clone("CountWeighted");
            }
            else {
                countPos->Add((TH1F*)file_initial->Get("CountPosWeight"));
                countNeg->Add((TH1F*)file_initial->Get("CountNegWeight"));
                countWeighted->Add((TH1F*)file_initial->Get("CountWeighted")); 
            }
            if (n!=0) file_initial->Close();
            
        }
        
        
        
        int nentries  = tree_initial->GetEntries();
        
        
        const int njets = 30;
        
        int nJets = 0;
        tree_initial->SetBranchAddress("nJet",&nJets);
        float Jet_pt[njets];
        tree_initial->SetBranchAddress("Jet_pt",Jet_pt);
        float Jet_eta[njets];
        tree_initial->SetBranchAddress("Jet_eta",Jet_eta);
        float Jet_phi[njets];
        tree_initial->SetBranchAddress("Jet_phi",Jet_phi);
        float Jet_mass[njets];
        tree_initial->SetBranchAddress("Jet_mass",Jet_mass);
        float Jet_btagCMVA[njets];
        tree_initial->SetBranchAddress("Jet_btagCMVA",Jet_btagCMVA);
        int Jet_id[njets];
        tree_initial->SetBranchAddress("Jet_id",Jet_id);	
        int Jet_puId[njets];
        tree_initial->SetBranchAddress("Jet_puId",Jet_puId);
        float puweight = 0;
        tree_initial->SetBranchAddress("puWeight",&puweight);
        float genweight = 0;
        tree_initial->SetBranchAddress("genWeight",&genweight);
        ULong64_t evt = 0;
        tree_initial->SetBranchAddress("evt",&evt);
        
        const int nlepton = 30;
        
        int nselLeptons;
        tree_initial->SetBranchAddress("nselLeptons",&nselLeptons);
        float selLeptons_pt[nlepton];
        tree_initial->SetBranchAddress("selLeptons_pt",selLeptons_pt);
        float selLeptons_eta[nlepton];
        tree_initial->SetBranchAddress("selLeptons_eta",selLeptons_eta);
        float selLeptons_phi[nlepton];
        tree_initial->SetBranchAddress("selLeptons_phi",selLeptons_phi);
        float selLeptons_mass[nlepton];
        tree_initial->SetBranchAddress("selLeptons_mass",selLeptons_mass);
        int  selLeptons_charge[nlepton];
        tree_initial->SetBranchAddress("selLeptons_charge",selLeptons_charge);
        int selLeptons_pdgId[nlepton];
        tree_initial->SetBranchAddress("selLeptons_pdgId",selLeptons_pdgId);
        int selLeptons_looseIdPOG[nlepton];
        tree_initial->SetBranchAddress("selLeptons_looseIdPOG",selLeptons_looseIdPOG);
        float selLeptons_relIso04[nlepton];
        tree_initial->SetBranchAddress("selLeptons_relIso04",selLeptons_relIso04);
        UInt_t lumi = 0;
        tree_initial->SetBranchAddress("lumi",&lumi);

        
        TFile * fileMVA = new TFile ("ROOT/"+nameOutputSample+".root", "recreate");
        TTree *treeMVA = new TTree("tree","tree");

        
        float recoMu_Mll=0;          
        treeMVA->Branch("recoMu_Mll",&recoMu_Mll,"recoMu_Mll/F");
        int nrecoMu=0;
        treeMVA->Branch("nrecoMu", &nrecoMu, "numberOfMuonRecostructed/I");
        int weight = 0;
        treeMVA->Branch("weight",&weight,"weight/I");
        float recoJet_Mjj=0;
        treeMVA->Branch("recoJet_Mjj",&recoJet_Mjj,"recoJet_Mjj/F");
        int selectionStep=0;
        treeMVA->Branch("selectionStep",&selectionStep,"selectionStep/I");
        int nrecoJet=0;
        treeMVA->Branch("nrecoJet",&nrecoJet,"nrecoJet/I");
        float recoJet_pt1 = 0;
        treeMVA->Branch("recoJet_pt1",&recoJet_pt1,"recoJet_pt1/F");
        float recoJet_pt2 = 0;
        treeMVA->Branch("recoJet_pt2",&recoJet_pt2,"recoJet_pt2/F");
        float qqDeltaEta = 0;
        treeMVA->Branch("qqDeltaEta",&qqDeltaEta,"qqDeltaEta/F");
        int lumiSection = 0;
        treeMVA->Branch("lumiSection",&lumiSection, "lumiSection/I");
        int eventNumber = 0;
        treeMVA->Branch("eventNumber",&eventNumber, "eventNumber/I");
        float Hll_zstar = 0;
        treeMVA->Branch("Hll_zstar",&Hll_zstar,"Hll_zstar/F");

        
        ofstream out_name;
        out_name.open("out_name.txt"); 
        out_name << "[[0]";


//         TH1F* countPos = (TH1F*)((TH1F*)file_initial->Get("CountPosWeight"))->Clone("CountPosWeight");
//         TH1F* countNeg = (TH1F*)((TH1F*)file_initial->Get("CountNegWeight"))->Clone("CountNegWeight");
//         TH1F* countWeighted = (TH1F*)((TH1F*)file_initial->Get("CountWeighted"))->Clone("CountWeighted");
        
        
        
        for (int entry=0; entry<nentries;++entry){            
            if (entry%10000 == 0) std::cout << "Writing " << entry << "th event" << std::endl;

                
                
            tree_initial->GetEntry(entry);
        
            recoMu_Mll=0;
            nrecoMu=0;    
            weight = 1;
            recoJet_Mjj=0;
            selectionStep=0;
            nrecoJet=0;
            Hll_zstar=0;
            
            
            if(genweight<0) weight = -1;
            eventNumber = evt;
            if (lumi != lumiSection) out_name << ", [" << lumi << "]";
            lumiSection = lumi;
            
            
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /////////////////////////////////////////////////////////// LEPTONS ////////////////////////////////////////////////////////////////////////////////////
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            TLorentzVector lepton1;
            TLorentzVector lepton2;      
            
            int count_l=0;
            int idx_1stLepton = 0;
            int idx_2ndLepton = 0;
            for (int i=0; i<nselLeptons;i++ ){
                if (!((selLeptons_looseIdPOG[i]>0) && (selLeptons_relIso04[i]<0.25) && (TMath::Abs(selLeptons_pdgId[i])==13 )) ) continue;
                if ((count_l==1) && (selLeptons_charge[idx_1stLepton]*selLeptons_charge[i] > 0)) continue;
                    if (count_l==1) {
                            idx_2ndLepton=i;
                            lepton2.SetPtEtaPhiM(selLeptons_pt[idx_2ndLepton], selLeptons_eta[idx_2ndLepton], selLeptons_phi[idx_2ndLepton], selLeptons_mass[idx_2ndLepton]);
                            count_l++;
                            break;
                    }
                    if (count_l==0) {
                                idx_1stLepton=i;
                            lepton1.SetPtEtaPhiM(selLeptons_pt[idx_1stLepton], selLeptons_eta[idx_1stLepton], selLeptons_phi[idx_1stLepton], selLeptons_mass[idx_1stLepton]);
                            count_l++;
                    }
            }


            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////// END LEPTONS //////////////////////////////////////////////////////////////////////////////////
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            
            
            
            

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            ///////////////////////////////////////////////////////////// JETS /////////////////////////////////////////////////////////////////////////////////////
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            
            vector<TLorentzVector> jets_pv;
            float maxBTagCMVA = 0;
            float maxSecondBTagCMVA = 0;
            int good_jets = 0;
            
            for (int i=0;i<nJets;i++){
                TLorentzVector jet0;
//                 if (!((Jet_id[i]>2)&&(Jet_puId[i]>0))) continue;
                    
                jet0.SetPtEtaPhiM(Jet_pt[i],Jet_eta[i],Jet_phi[i],Jet_mass[i]);


                if (maxBTagCMVA < Jet_btagCMVA[i]) {
                    maxSecondBTagCMVA = maxBTagCMVA;
                    maxBTagCMVA = Jet_btagCMVA[i];
                }

                if (maxBTagCMVA > Jet_btagCMVA[i] && maxSecondBTagCMVA < Jet_btagCMVA[i]) maxSecondBTagCMVA = Jet_btagCMVA[i];

                bool condition = false;
                    
                if (good_jets < 2) condition = true;
                else if (jet0.Eta() < max(jets_pv[0].Eta(), jets_pv[1].Eta()) && jet0.Eta() > min(jets_pv[0].Eta(), jets_pv[1].Eta())) condition = true;  
                if (1) {
                    jets_pv.push_back(jet0);
//                     jets_indices.push_back(i);
                    good_jets++;
                }
            }
        
            
            
            

            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            /////////////////////////////////////////////////////////// END JETS ///////////////////////////////////////////////////////////////////////////////////
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            
            
      
            nrecoMu=count_l;
            nrecoJet = jets_pv.size();
            if (count_l>1) recoMu_Mll = (lepton1 + lepton2).M();
            if(jets_pv.size() > 0)  recoJet_pt1 = jets_pv[0].Pt();

        
            if(jets_pv.size() > 1) {
                selectionStep = 1; 
                recoJet_pt2 = jets_pv[1].Pt();
                
                TLorentzVector qq_p4 =  jets_pv[0] + jets_pv[1];
                recoJet_Mjj = qq_p4.M();
                qqDeltaEta = abs(jets_pv[0].Eta() - jets_pv[1].Eta());
        
                
                if(count_l == 2) {
                    selectionStep = 2;
                
                    TLorentzVector Hll_p4 =  lepton1 + lepton2;
                    float Hll_p4_mass = Hll_p4.M();
                    float Hll_ystar = Hll_p4.Rapidity() - (jets_pv[0].Rapidity() + jets_pv[1].Rapidity()) ;
                    Hll_zstar = TMath::Abs( Hll_ystar/ (jets_pv[0].Rapidity()-jets_pv[1].Rapidity() )) ;
                                                                
                                                                
                                  
                    if (Hll_p4_mass > 110) {
                         selectionStep = 3;
                    
                
                        if (Hll_p4_mass < 145) {
                            selectionStep = 4;

                            if ( qqDeltaEta > 2.5) {
                                selectionStep = 5;
                                                                
                                if (jets_pv[0].Pt() > 35) {
                                    selectionStep = 6;
                                
                                    if (jets_pv[1].Pt() > 25) {                   
                                        selectionStep = 7;
                                    
                                        if ( recoJet_Mjj > 200) {
                                            selectionStep = 8;
                                                                    
                                            if (lepton1.Pt() > 30) {
                                                selectionStep = 9;
                                            
                                                if (lepton2.Pt() > 10) {                   
                                                    selectionStep = 10;                            
                                    
                                                
                                                    if (abs(lepton1.Eta()) < 2.4) {
                                                        selectionStep = 11;
                                                    
                                                        if (abs(lepton2.Eta()) < 2.4) {                   
                                                            selectionStep = 12;                     
                                    
                                                            if (maxBTagCMVA<0.95) {
                                                                selectionStep = 13;
                                                                
                                                                                        
                                                                if (Hll_zstar < 2.5) {
                                                                    selectionStep = 14;


                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }                                                 
            
            
                
        
            treeMVA->Fill();
        }
        
        
        
        



        
        out_name << "]" << std::endl;
        out_name.close();
        
         
        countPos->Write();
        countNeg->Write();
        countWeighted->Write();
        treeMVA->Write();
        fileMVA->Close();   
        


}








