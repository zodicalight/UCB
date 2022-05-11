{
#include <vector>

// read data from signal and bkg files


//None Resonant background
TChain *NR_ch = new TChain("analysis");
NR_ch->Add("NR4l.root/analysis");
NR_ch->Add("NRGG.root/analysis");
TTree *NR = NR_ch->CopyTree("");
  
/*
//NR4l->Higgs
TString NR4l_path="NR4l.root";
TFile NR4l_File(NR4l_path.Data(),"NR4l");
TTree *NR4l = NR4l_File.Get<TTree>("analysis");
    
//NRGG->Higgs
TString NRGG_path="NRGG.root";
TFile NRGG_File(NRGG_path.Data(),"NRGG");
TTree *NRGG = NRGG_File.Get<TTree>("analysis");
*/
 

//ggF->Higgs
TString ggF_path="ggF.root";
TFile ggF_File(ggF_path.Data(),"ggF");
TTree *ggF = ggF_File.Get<TTree>("analysis");

    //signal
TString sig_path="Higgs24ls.root";
TFile sig_File(sig_path.Data(),"sig");
TTree *sig = sig_File.Get<TTree>("analysis");



//Get the viriables from root files

/*TString variable_list[]={"ElectronsPt","ElectronsEta","ElectronsE","MuonsE","MuonsPt","MuonsEta"};*/

    TString variable_list[]={"ElectronsEta_sig","ElectronsE_sig","ElectronsPhi_sig","ElectronsPt_sig","MuonsEta_sig","MuonsPt_sig","MuonsPhi_sig","MuonsE_sig","JetsEta_sig","JetsPt_sig","JetsPhi_sig",
        "M12_sig","Pt12_sig","Eta12_sig","R12_sig","Phi12_sig","DeltaR12_sig","M34_sig","Pt34_sig","Eta34_sig","R34_sig","Phi34_sig","DeltaR34_sig","DeltaRZZ_sig","HiggsM_sig","HiggsPt_sig","HiggsEta_sig","HiggsR_sig","HiggsPhi_sig","M1_sig","M2_sig","Pt1_sig","Pt2_sig","Eta1_sig","Eta2_sig","Phi1_sig","Phi2_sig","M3_sig","M4_sig","Pt3_sig","Pt4_sig","Eta3_sig","Eta4_sig","Phi3_sig","Phi4_sig","EventWeight_sig",
       "ElectronsEta_NR","ElectronsE_NR","ElectronsPhi_NR","ElectronsPt_NR","MuonsEta_NR","MuonsPt_NR","MuonsPhi_NR","MuonsE_NR","JetsEta_NR","JetsPt_NR","JetsPhi_NR",
       "M12_NR","Pt12_NR","Eta12_NR","R12_NR","Phi12_NR","DeltaR12_NR","M34_NR","Pt34_NR","Eta34_NR","R34_NR","Phi34_NR","DeltaR34_NR","DeltaRZZ_NR","HiggsM_NR","HiggsPt_NR","HiggsEta_NR","HiggsR_NR","HiggsPhi_NR","M1_NR","M2_NR","Pt1_NR","Pt2_NR","Eta1_NR","Eta2_NR","Phi1_NR","Phi2_NR","M3_NR","M4_NR","Pt3_NR","Pt4_NR","Eta3_NR","Eta4_NR","Phi3_NR","Phi4_NR","EventWeight_NR",
       "ElectronsEta_ggF","ElectronsE_ggF","ElectronsPhi_ggF","ElectronsPt_ggF","MuonsEta_ggF","MuonsPt_ggF","MuonsPhi_ggF","MuonsE_ggF","JetsEta_ggF","JetsPt_ggF","JetsPhi_ggF",
       "M12_ggF","Pt12_ggF","Eta12_ggF","R12_ggF","Phi12_ggF","DeltaR12_ggF","M34_ggF","Pt34_ggF","Eta34_ggF","R34_ggF","Phi34_ggF","DeltaR34_ggF","DeltaRZZ_ggF","HiggsM_ggF","HiggsPt_ggF","HiggsEta_ggF","HiggsR_ggF","HiggsPhi_ggF","M1_ggF","M2_ggF","Pt1_ggF","Pt2_ggF","Eta1_ggF","Eta2_ggF","Phi1_ggF","Phi2_ggF","M3_ggF","M4_ggF","Pt3_ggF","Pt4_ggF","Eta3_ggF","Eta4_ggF","Phi3_ggF","Phi4_ggF","EventWeight_ggF"
    };


    vector<float> *ElectronsEta_sig,*ElectronsE_sig,*ElectronsPhi_sig,*ElectronsPt_sig,*MuonsEta_sig,*MuonsPt_sig,*MuonsPhi_sig,*MuonsE_sig,*JetsEta_sig,*JetsPt_sig,*JetsPhi_sig;
    float M12_sig,Pt12_sig,Eta12_sig,R12_sig,Phi12_sig,DeltaR12_sig,M34_sig,Pt34_sig,Eta34_sig,R34_sig,Phi34_sig,DeltaR34_sig,DeltaRZZ_sig,HiggsM_sig,HiggsPt_sig,HiggsEta_sig,HiggsR_sig,HiggsPhi_sig,M1_sig,M2_sig,Pt1_sig,Pt2_sig,Eta1_sig,Eta2_sig,Phi1_sig,Phi2_sig,M3_sig,M4_sig,Pt3_sig,Pt4_sig,Eta3_sig,Eta4_sig,Phi3_sig,Phi4_sig,EventWeight_sig;

    vector<float> *ElectronsEta_NR,*ElectronsE_NR,*ElectronsPhi_NR,*ElectronsPt_NR,*MuonsEta_NR,*MuonsPt_NR,*MuonsPhi_NR,*MuonsE_NR,*JetsEta_NR,*JetsPt_NR,*JetsPhi_NR;
    float M12_NR,Pt12_NR,Eta12_NR,R12_NR,Phi12_NR,DeltaR12_NR,M34_NR,Pt34_NR,Eta34_NR,R34_NR,Phi34_NR,DeltaR34_NR,DeltaRZZ_NR,HiggsM_NR,HiggsPt_NR,HiggsEta_NR,HiggsR_NR,HiggsPhi_NR,M1_NR,M2_NR,Pt1_NR,Pt2_NR,Eta1_NR,Eta2_NR,Phi1_NR,Phi2_NR,M3_NR,M4_NR,Pt3_NR,Pt4_NR,Eta3_NR,Eta4_NR,Phi3_NR,Phi4_NR,EventWeight_NR;

    vector<float> *ElectronsEta_ggF,*ElectronsE_ggF,*ElectronsPhi_ggF,*ElectronsPt_ggF,*MuonsEta_ggF,*MuonsPt_ggF,*MuonsPhi_ggF,*MuonsE_ggF,*JetsEta_ggF,*JetsPt_ggF,*JetsPhi_ggF;
    float M12_ggF,Pt12_ggF,Eta12_ggF,R12_ggF,Phi12_ggF,DeltaR12_ggF,M34_ggF,Pt34_ggF,Eta34_ggF,R34_ggF,Phi34_ggF,DeltaR34_ggF,DeltaRZZ_ggF,HiggsM_ggF,HiggsPt_ggF,HiggsEta_ggF,HiggsR_ggF,HiggsPhi_ggF,M1_ggF,M2_ggF,Pt1_ggF,Pt2_ggF,Eta1_ggF,Eta2_ggF,Phi1_ggF,Phi2_ggF,M3_ggF,M4_ggF,Pt3_ggF,Pt4_ggF,Eta3_ggF,Eta4_ggF,Phi3_ggF,Phi4_ggF,EventWeight_ggF;
    
    //None Resonant
    //    vector<float> *ElectronsEta_sig,*ElectronsE_sig,*ElectronsPhi_sig,*ElectronsPt_sig,*MuonsEta_sig,*MuonsPt_sig,*MuonsE_sig,*MuonsPhi_sig,*JetsEta_sig,*JetsPt_sig,*M12_sig,*Pt12_sig,*Eta12_sig,*R12_sig,*Phi12_sig,*M34_sig,*Pt34_sig,*Eta34_sig,*R34_sig,*Phi34_sig,*HiggsM_sig,*HiggsPt_sig,*HiggsEta_sig,*HiggsR_sig,*HiggsPhi_sig;
    //signal
    //vector<float> *ElectronsPt_sig, *ElectronsEta_sig, *ElectronsE_sig, *MuonsE_sig, *MuonsPt_sig, *MuonsEta_sig;

    //set the path of variable

    //sig
    /*
    sig->SetBranchAddress("ElectronsEta",&ElectronsEta_sig);
    sig->SetBranchAddress("ElectronsE",&ElectronsE_sig);
    sig->SetBranchAddress("ElectronsPhi",&ElectronsPhi_sig);
    sig->SetBranchAddress("ElectronsPt",&ElectronsPt_sig);
    sig->SetBranchAddress("MuonsEta",&MuonsEta_sig);
    sig->SetBranchAddress("MuonsPt",&MuonsPt_sig);
    sig->SetBranchAddress("MuonsE",&MuonsE_sig);
    sig->SetBranchAddress("MuonsPhi",&MuonsPhi_sig);
    sig->SetBranchAddress("JetsEta",&JetsEta_sig);
    sig->SetBranchAddress("JetsPt",&JetsPt_sig);
    sig->SetBranchAddress("JetsPt",&JetsPhi_sig);
     */

    sig->SetBranchAddress("M12",&M12_sig);
    sig->SetBranchAddress("Pt12",&Pt12_sig);
    sig->SetBranchAddress("Eta12",&Eta12_sig);
    sig->SetBranchAddress("R12",&R12_sig);
    sig->SetBranchAddress("Phi12",&Phi12_sig);
    sig->SetBranchAddress("DeltaR12",&DeltaR12_sig);
    sig->SetBranchAddress("M34",&M34_sig);
    sig->SetBranchAddress("Pt34",&Pt34_sig);
    sig->SetBranchAddress("Eta34",&Eta34_sig);
    sig->SetBranchAddress("R34",&R34_sig);
    sig->SetBranchAddress("Phi34",&Phi34_sig);
    sig->SetBranchAddress("DeltaR34",&DeltaR34_sig);
    sig->SetBranchAddress("DeltaRZZ",&DeltaRZZ_sig);
    sig->SetBranchAddress("HiggsM",&HiggsM_sig);
    sig->SetBranchAddress("HiggsPt",&HiggsPt_sig);
    sig->SetBranchAddress("HiggsEta",&HiggsEta_sig);
    sig->SetBranchAddress("HiggsR",&HiggsR_sig);
    sig->SetBranchAddress("HiggsPhi",&HiggsPhi_sig);

    sig->SetBranchAddress("M1",&M1_sig);
    sig->SetBranchAddress("Pt1",&Pt1_sig);
    sig->SetBranchAddress("Eta1",&Eta1_sig);
    sig->SetBranchAddress("Phi1",&Phi1_sig);
    sig->SetBranchAddress("M2",&M2_sig);
    sig->SetBranchAddress("Pt2",&Pt2_sig);
    sig->SetBranchAddress("Eta2",&Eta2_sig);
    sig->SetBranchAddress("Phi2",&Phi2_sig);
    sig->SetBranchAddress("M3",&M3_sig);
    sig->SetBranchAddress("Pt3",&Pt3_sig);
    sig->SetBranchAddress("Eta3",&Eta3_sig);
    sig->SetBranchAddress("Phi3",&Phi3_sig);
    sig->SetBranchAddress("M4",&M4_sig);
    sig->SetBranchAddress("Pt4",&Pt4_sig);
    sig->SetBranchAddress("Eta4",&Eta4_sig);
    sig->SetBranchAddress("Phi4",&Phi4_sig);
    sig->SetBranchAddress("EventWeight",&EventWeight_sig);
    
    //NR
    /*
    NR->SetBranchAddress("ElectronsEta",&ElectronsEta_NR);
    NR->SetBranchAddress("ElectronsE",&ElectronsE_NR);
    NR->SetBranchAddress("ElectronsPhi",&ElectronsPhi_NR);
    NR->SetBranchAddress("ElectronsPt",&ElectronsPt_NR);
    NR->SetBranchAddress("MuonsEta",&MuonsEta_NR);
    NR->SetBranchAddress("MuonsPt",&MuonsPt_NR);
    NR->SetBranchAddress("MuonsE",&MuonsE_NR);
    NR->SetBranchAddress("MuonsPhi",&MuonsPhi_NR);
    NR->SetBranchAddress("JetsEta",&JetsEta_NR);
    NR->SetBranchAddress("JetsPt",&JetsPt_NR);
    NR->SetBranchAddress("JetsPt",&JetsPhi_NR);
     */

    NR->SetBranchAddress("M12",&M12_NR);
    NR->SetBranchAddress("Pt12",&Pt12_NR);
    NR->SetBranchAddress("Eta12",&Eta12_NR);
    NR->SetBranchAddress("R12",&R12_NR);
    NR->SetBranchAddress("Phi12",&Phi12_NR);
    NR->SetBranchAddress("DeltaR12",&DeltaR12_NR);
    NR->SetBranchAddress("M34",&M34_NR);
    NR->SetBranchAddress("Pt34",&Pt34_NR);
    NR->SetBranchAddress("Eta34",&Eta34_NR);
    NR->SetBranchAddress("R34",&R34_NR);
    NR->SetBranchAddress("Phi34",&Phi34_NR);
    NR->SetBranchAddress("DeltaR34",&DeltaR34_NR);
    NR->SetBranchAddress("DeltaRZZ",&DeltaRZZ_NR);
    NR->SetBranchAddress("HiggsM",&HiggsM_NR);
    NR->SetBranchAddress("HiggsPt",&HiggsPt_NR);
    NR->SetBranchAddress("HiggsEta",&HiggsEta_NR);
    NR->SetBranchAddress("HiggsR",&HiggsR_NR);
    NR->SetBranchAddress("HiggsPhi",&HiggsPhi_NR);

    NR->SetBranchAddress("M1",&M1_NR);
    NR->SetBranchAddress("Pt1",&Pt1_NR);
    NR->SetBranchAddress("Eta1",&Eta1_NR);
    NR->SetBranchAddress("Phi1",&Phi1_NR);
    NR->SetBranchAddress("M2",&M2_NR);
    NR->SetBranchAddress("Pt2",&Pt2_NR);
    NR->SetBranchAddress("Eta2",&Eta2_NR);
    NR->SetBranchAddress("Phi2",&Phi2_NR);
    NR->SetBranchAddress("M3",&M3_NR);
    NR->SetBranchAddress("Pt3",&Pt3_NR);
    NR->SetBranchAddress("Eta3",&Eta3_NR);
    NR->SetBranchAddress("Phi3",&Phi3_NR);
    NR->SetBranchAddress("M4",&M4_NR);
    NR->SetBranchAddress("Pt4",&Pt4_NR);
    NR->SetBranchAddress("Eta4",&Eta4_NR);
    NR->SetBranchAddress("Phi4",&Phi4_NR);
    NR->SetBranchAddress("EventWeight",&EventWeight_NR);
    
    
    //ggF
    /*
    ggF->SetBranchAddress("ElectronsEta",&ElectronsEta_ggF);
    ggF->SetBranchAddress("ElectronsE",&ElectronsE_ggF);
    ggF->SetBranchAddress("ElectronsPhi",&ElectronsPhi_ggF);
    ggF->SetBranchAddress("ElectronsPt",&ElectronsPt_ggF);
    ggF->SetBranchAddress("MuonsEta",&MuonsEta_ggF);
    ggF->SetBranchAddress("MuonsPt",&MuonsPt_ggF);
    ggF->SetBranchAddress("MuonsE",&MuonsE_ggF);
    ggF->SetBranchAddress("MuonsPhi",&MuonsPhi_ggF);
    ggF->SetBranchAddress("JetsEta",&JetsEta_ggF);
    ggF->SetBranchAddress("JetsPt",&JetsPt_ggF);
    ggF->SetBranchAddress("JetsPt",&JetsPhi_ggF);
     */

    ggF->SetBranchAddress("M12",&M12_ggF);
    ggF->SetBranchAddress("Pt12",&Pt12_ggF);
    ggF->SetBranchAddress("Eta12",&Eta12_ggF);
    ggF->SetBranchAddress("R12",&R12_ggF);
    ggF->SetBranchAddress("Phi12",&Phi12_ggF);
    ggF->SetBranchAddress("DeltaR12",&DeltaR12_ggF);
    ggF->SetBranchAddress("M34",&M34_ggF);
    ggF->SetBranchAddress("Pt34",&Pt34_ggF);
    ggF->SetBranchAddress("Eta34",&Eta34_ggF);
    ggF->SetBranchAddress("R34",&R34_ggF);
    ggF->SetBranchAddress("Phi34",&Phi34_ggF);
    ggF->SetBranchAddress("DeltaR34",&DeltaR34_ggF);
    ggF->SetBranchAddress("DeltaRZZ",&DeltaRZZ_ggF);
    ggF->SetBranchAddress("HiggsM",&HiggsM_ggF);
    ggF->SetBranchAddress("HiggsPt",&HiggsPt_ggF);
    ggF->SetBranchAddress("HiggsEta",&HiggsEta_ggF);
    ggF->SetBranchAddress("HiggsR",&HiggsR_ggF);
    ggF->SetBranchAddress("HiggsPhi",&HiggsPhi_ggF);

    ggF->SetBranchAddress("M1",&M1_ggF);
    ggF->SetBranchAddress("Pt1",&Pt1_ggF);
    ggF->SetBranchAddress("Eta1",&Eta1_ggF);
    ggF->SetBranchAddress("Phi1",&Phi1_ggF);
    ggF->SetBranchAddress("M2",&M2_ggF);
    ggF->SetBranchAddress("Pt2",&Pt2_ggF);
    ggF->SetBranchAddress("Eta2",&Eta2_ggF);
    ggF->SetBranchAddress("Phi2",&Phi2_ggF);
    ggF->SetBranchAddress("M3",&M3_ggF);
    ggF->SetBranchAddress("Pt3",&Pt3_ggF);
    ggF->SetBranchAddress("Eta3",&Eta3_ggF);
    ggF->SetBranchAddress("Phi3",&Phi3_ggF);
    ggF->SetBranchAddress("M4",&M4_ggF);
    ggF->SetBranchAddress("Pt4",&Pt4_ggF);
    ggF->SetBranchAddress("Eta4",&Eta4_ggF);
    ggF->SetBranchAddress("Phi4",&Phi4_ggF);
    ggF->SetBranchAddress("EventWeight",&EventWeight_ggF);

                
    //None Resonant
    /*
    NR->SetBranchAddress("ElectronsPt",&ElectronsPt_NR);
    NR->SetBranchAddress("ElectronsEta",&ElectronsEta_NR);
    NR->SetBranchAddress("ElectronsE",&ElectronsE_NR);
    NR->SetBranchAddress("MuonsPt",&MuonsPt_NR);
    NR->SetBranchAddress("MuonsEta",&MuonsEta_NR);
    NR->SetBranchAddress("MuonsE",&MuonsE_NR);

    //signal
    sig->SetBranchAddress("ElectronsPt",&ElectronsPt_sig);
    sig->SetBranchAddress("ElectronsEta",&ElectronsEta_sig);
    sig->SetBranchAddress("ElectronsE",&ElectronsE_sig);
    sig->SetBranchAddress("MuonsPt",&MuonsPt_sig);
    sig->SetBranchAddress("MuonsEta",&MuonsEta_sig);
    sig->SetBranchAddress("MuonsE",&MuonsE_sig);
    */
    //create Hist

    //sig
    /*
    TH1F *hist_ElectronsEta_sig=new TH1F("ElectronsEta_sig","ElectronsEta_sig",100,-4,4);
    TH1F *hist_ElectronsE_sig=new TH1F("ElectronsE_sig","ElectronsE_sig",100,0,800000);
    TH1F *hist_ElectronsPhi_sig=new TH1F("ElectronsPhi_sig","ElectronsPhi_sig",100,-4,4);
    TH1F *hist_ElectronsPt_sig=new TH1F("ElectronsPt_sig","ElectronsPt_sig",100,0,500000);
    TH1F *hist_MuonsEta_sig=new TH1F("MuonsEta_sig","MuonsEta_sig",100,-4,4);
    TH1F *hist_MuonsPt_sig=new TH1F("MuonsPt_sig","MuonsPt_sig",100,0,800000);
    TH1F *hist_MuonsE_sig=new TH1F("MuonsE_sig","MuonsE_sig",100,0,800000);
    TH1F *hist_MuonsPhi_sig=new TH1F("MuonsPhi_sig","MuonsPt_sig",100,-4,4);
    TH1F *hist_JetsEta_sig=new TH1F("JetsEta_sig","JetsEta_sig",100,-4,4);
    TH1F *hist_JetsPt_sig=new TH1F("JetsPt_sig","JetsPt_sig",100,0,900000);
    TH1F *hist_JetsPhi_sig=new TH1F("JetsPhi_sig","JetsPhi_sig",100,-4,4);
     */
   
    TH1F *hist_M12_sig=new TH1F("M12_sig","M12_sig",100,0,140000);
    TH1F *hist_Pt12_sig=new TH1F("Pt12_sig","Pt12_sig",100,0,700000);
    TH1F *hist_Eta12_sig=new TH1F("Eta12_sig","Eta12_sig",100,-8,8);
    TH1F *hist_R12_sig=new TH1F("R12_sig","R12_sig",100,-4,4);
    TH1F *hist_Phi12_sig=new TH1F("Phi12_sig","Phi12_sig",100,-4,4);
    TH1F *hist_DeltaR12_sig=new TH1F("DeltaR12_sig","DeltaR12_sig",100,0,6);
    ///
    TH1F *hist_M34_sig=new TH1F("M34_sig","M34_sig",100,0,140000);
    TH1F *hist_Pt34_sig=new TH1F("Pt34_sig","Pt34_sig",100,0,600000);
    TH1F *hist_Eta34_sig=new TH1F("Eta34_sig","Eta34_sig",100,-4,4);
    TH1F *hist_R34_sig=new TH1F("R34_sig","R34_sig",100,-4,4);
    TH1F *hist_Phi34_sig=new TH1F("Phi34_sig","Phi34_sig",100,-4,4);
    TH1F *hist_DeltaR34_sig=new TH1F("DeltaR34_sig","DeltaR34_sig",100,0,6);
    TH1F *hist_DeltaRZZ_sig=new TH1F("DeltaRZZ_sig","DeltaRZZ_sig",100,0,6);
    
    TH1F *hist_HiggsM_sig=new TH1F("HiggsM_sig","HiggsM_sig",100,-20000,250000);
    TH1F *hist_HiggsPt_sig=new TH1F("HiggsPt_sig","HiggsPt_sig",100,0,500000);
    TH1F *hist_HiggsEta_sig=new TH1F("HiggsEta_sig","HiggsEta_sig",100,-6,6);
    TH1F *hist_HiggsR_sig=new TH1F("HiggsR_sig","HiggsR_sig",100,-4,4);
    TH1F *hist_HiggsPhi_sig=new TH1F("HiggsPhi_sig","HiggsPhi_sig",100,-4,4);

    TH1F *hist_M1_sig=new TH1F("M1_sig","M1_sig",100,0,200);
    TH1F *hist_Pt1_sig=new TH1F("Pt1_sig","Pt1_sig",100,0,400000);
    TH1F *hist_Eta1_sig=new TH1F("Eta1_sig","Eta1_sig",100,-4,4);
    TH1F *hist_Phi1_sig=new TH1F("Phi1_sig","Phi1_sig",100,-4,4);
    
    TH1F *hist_M2_sig=new TH1F("M2_sig","M2_sig",100,0,200);
    TH1F *hist_Pt2_sig=new TH1F("Pt2_sig","Pt2_sig",100,0,600000);
    TH1F *hist_Eta2_sig=new TH1F("Eta2_sig","Eta2_sig",100,-4,4);
    TH1F *hist_Phi2_sig=new TH1F("Phi2_sig","Phi2_sig",100,-4,4);
    
    TH1F *hist_M3_sig=new TH1F("M3_sig","M3_sig",100,0,200);
    TH1F *hist_Pt3_sig=new TH1F("Pt3_sig","Pt3_sig",100,0,600000);
    TH1F *hist_Eta3_sig=new TH1F("Eta3_sig","Eta3_sig",100,-4,4);
    TH1F *hist_Phi3_sig=new TH1F("Phi3_sig","Phi3_sig",100,-4,4);
    
    TH1F *hist_M4_sig=new TH1F("M4_sig","M4_sig",100,0,200);
    TH1F *hist_Pt4_sig=new TH1F("Pt4_sig","Pt4_sig",100,0,100000);
    TH1F *hist_Eta4_sig=new TH1F("Eta4_sig","Eta4_sig",100,-4,4);
    TH1F *hist_Phi4_sig=new TH1F("Phi4_sig","Phi4_sig",100,-4,4);



    //NR4l
    /*
    TH1F *hist_ElectronsEta_NR=new TH1F("ElectronsEta_NR","ElectronsEta_NR",100,-4,4);
    TH1F *hist_ElectronsE_NR=new TH1F("ElectronsE_NR","ElectronsE_NR",100,0,800000);
    TH1F *hist_ElectronsPhi_NR=new TH1F("ElectronsPhi_NR","ElectronsPhi_NR",100,-4,4);
    TH1F *hist_ElectronsPt_NR=new TH1F("ElectronsPt_NR","ElectronsPt_NR",100,0,500000);
    TH1F *hist_MuonsEta_NR=new TH1F("MuonsEta_NR","MuonsEta_NR",100,-4,4);
    TH1F *hist_MuonsPt_NR=new TH1F("MuonsPt_NR","MuonsPt_NR",100,0,800000);
    TH1F *hist_MuonsE_NR=new TH1F("MuonsE_NR","MuonsE_NR",100,0,800000);
    TH1F *hist_MuonsPhi_NR=new TH1F("MuonsPhi_NR","MuonsPt_NR",100,-4,4);
    TH1F *hist_JetsEta_NR=new TH1F("JetsEta_NR","JetsEta_NR",100,-4,4);
    TH1F *hist_JetsPt_NR=new TH1F("JetsPt_NR","JetsPt_NR",100,0,900000);
    TH1F *hist_JetsPhi_NR=new TH1F("JetsPhi_NR","JetsPhi_NR",100,-4,4);
     */

    TH1F *hist_M12_NR=new TH1F("M12_NR","M12_NR",100,0,140000);
    TH1F *hist_Pt12_NR=new TH1F("Pt12_NR","Pt12_NR",100,0,700000);
    TH1F *hist_Eta12_NR=new TH1F("Eta12_NR","Eta12_NR",100,-8,8);
    TH1F *hist_R12_NR=new TH1F("R12_NR","R12_NR",100,-4,4);
    TH1F *hist_Phi12_NR=new TH1F("Phi12_NR","Phi12_NR",100,-4,4);
    TH1F *hist_DeltaR12_NR=new TH1F("Delta12_NR","DeltaR12_NR",100,0,6);
    ///
    TH1F *hist_M34_NR=new TH1F("M34_NR","M34_NR",100,0,140000);
    TH1F *hist_Pt34_NR=new TH1F("Pt34_NR","Pt34_NR",100,0,600000);
    TH1F *hist_Eta34_NR=new TH1F("Eta34_NR","Eta34_NR",100,-4,4);
    TH1F *hist_R34_NR=new TH1F("R34_NR","R34_NR",100,-4,4);
    TH1F *hist_Phi34_NR=new TH1F("Phi34_NR","Phi34_NR",100,-4,4);
    TH1F *hist_DeltaR34_NR=new TH1F("DeltaR34_NR","DeltaR34_NR",100,0,6);
    TH1F *hist_DeltaRZZ_NR=new TH1F("DeltaRZZ_NR","DeltaRZZ_NR",100,0,6);

    TH1F *hist_HiggsM_NR=new TH1F("HiggsM_NR","HiggsM_NR",100,-20000,250000);
    TH1F *hist_HiggsPt_NR=new TH1F("HiggsPt_NR","HiggsPt_NR",100,0,500000);
    TH1F *hist_HiggsEta_NR=new TH1F("HiggsEta_NR","HiggsEta_NR",100,-6,6);
    TH1F *hist_HiggsR_NR=new TH1F("HiggsR_NR","HiggsR_NR",100,-4,4);
    TH1F *hist_HiggsPhi_NR=new TH1F("HiggsPhi_NR","HiggsPhi_NR",100,-4,4);

    TH1F *hist_M1_NR=new TH1F("M1_NR","M1_NR",100,0,200);
    TH1F *hist_Pt1_NR=new TH1F("Pt1_NR","Pt1_NR",100,0,400000);
    TH1F *hist_Eta1_NR=new TH1F("Eta1_NR","Eta1_NR",100,-4,4);
    TH1F *hist_Phi1_NR=new TH1F("Phi1_NR","Phi1_NR",100,-4,4);

    TH1F *hist_M2_NR=new TH1F("M2_NR","M2_NR",100,0,200);
    TH1F *hist_Pt2_NR=new TH1F("Pt2_NR","Pt2_NR",100,0,600000);
    TH1F *hist_Eta2_NR=new TH1F("Eta2_NR","Eta2_NR",100,-4,4);
    TH1F *hist_Phi2_NR=new TH1F("Phi2_NR","Phi2_NR",100,-4,4);

    TH1F *hist_M3_NR=new TH1F("M3_NR","M3_NR",100,0,200);
    TH1F *hist_Pt3_NR=new TH1F("Pt3_NR","Pt3_NR",100,0,600000);
    TH1F *hist_Eta3_NR=new TH1F("Eta3_NR","Eta3_NR",100,-4,4);
    TH1F *hist_Phi3_NR=new TH1F("Phi3_NR","Phi3_NR",100,-4,4);

    TH1F *hist_M4_NR=new TH1F("M4_NR","M4_NR",100,0,200);
    TH1F *hist_Pt4_NR=new TH1F("Pt4_NR","Pt4_NR",100,0,100000);
    TH1F *hist_Eta4_NR=new TH1F("Eta4_NR","Eta4_NR",100,-4,4);
    TH1F *hist_Phi4_NR=new TH1F("Phi4_NR","Phi4_NR",100,-4,4);



    //ggF
    /*
    TH1F *hist_ElectronsEta_ggF=new TH1F("ElectronsEta_ggF","ElectronsEta_ggF",100,-4,4);
    TH1F *hist_ElectronsE_ggF=new TH1F("ElectronsE_ggF","ElectronsE_ggF",100,0,800000);
    TH1F *hist_ElectronsPhi_ggF=new TH1F("ElectronsPhi_ggF","ElectronsPhi_ggF",100,-4,4);
    TH1F *hist_ElectronsPt_ggF=new TH1F("ElectronsPt_ggF","ElectronsPt_ggF",100,0,500000);
    TH1F *hist_MuonsEta_ggF=new TH1F("MuonsEta_ggF","MuonsEta_ggF",100,-4,4);
    TH1F *hist_MuonsPt_ggF=new TH1F("MuonsPt_ggF","MuonsPt_ggF",100,0,800000);
    TH1F *hist_MuonsE_ggF=new TH1F("MuonsE_ggF","MuonsE_ggF",100,0,800000);
    TH1F *hist_MuonsPhi_ggF=new TH1F("MuonsPhi_ggF","MuonsPt_ggF",100,-4,4);
    TH1F *hist_JetsEta_ggF=new TH1F("JetsEta_ggF","JetsEta_ggF",100,-4,4);
    TH1F *hist_JetsPt_ggF=new TH1F("JetsPt_ggF","JetsPt_ggF",100,0,900000);
    TH1F *hist_JetsPhi_ggF=new TH1F("JetsPhi_ggF","JetsPhi_ggF",100,-4,4);
     */

    TH1F *hist_M12_ggF=new TH1F("M12_ggF","M12_ggF",100,0,140000);
    TH1F *hist_Pt12_ggF=new TH1F("Pt12_ggF","Pt12_ggF",100,0,700000);
    TH1F *hist_Eta12_ggF=new TH1F("Eta12_ggF","Eta12_ggF",100,-8,8);
    TH1F *hist_R12_ggF=new TH1F("R12_ggF","R12_ggF",100,-4,4);
    TH1F *hist_Phi12_ggF=new TH1F("Phi12_ggF","Phi12_ggF",100,-4,4);
    TH1F *hist_DeltaR12_ggF=new TH1F("Delta12_ggF","DeltaR12_ggF",100,0,6);
    ///
    TH1F *hist_M34_ggF=new TH1F("M34_ggF","M34_ggF",100,0,140000);
    TH1F *hist_Pt34_ggF=new TH1F("Pt34_ggF","Pt34_ggF",100,0,600000);
    TH1F *hist_Eta34_ggF=new TH1F("Eta34_ggF","Eta34_ggF",100,-4,4);
    TH1F *hist_R34_ggF=new TH1F("R34_ggF","R34_ggF",100,-4,4);
    TH1F *hist_Phi34_ggF=new TH1F("Phi34_ggF","Phi34_ggF",100,-4,4);
    TH1F *hist_DeltaR34_ggF=new TH1F("Delta34_ggF","DeltaR34_ggF",100,0,6);
    TH1F *hist_DeltaRZZ_ggF=new TH1F("DeltaRZZ_ggF","DeltaRZZ_ggF",100,0,6);
    
    TH1F *hist_HiggsM_ggF=new TH1F("HiggsM_ggF","HiggsM_ggF",100,-20000,250000);
    TH1F *hist_HiggsPt_ggF=new TH1F("HiggsPt_ggF","HiggsPt_ggF",100,0,500000);
    TH1F *hist_HiggsEta_ggF=new TH1F("HiggsEta_ggF","HiggsEta_ggF",100,-6,6);
    TH1F *hist_HiggsR_ggF=new TH1F("HiggsR_ggF","HiggsR_ggF",100,-4,4);
    TH1F *hist_HiggsPhi_ggF=new TH1F("HiggsPhi_ggF","HiggsPhi_ggF",100,-4,4);

    TH1F *hist_M1_ggF=new TH1F("M1_ggF","M1_ggF",100,0,200);
    TH1F *hist_Pt1_ggF=new TH1F("Pt1_ggF","Pt1_ggF",100,0,400000);
    TH1F *hist_Eta1_ggF=new TH1F("Eta1_ggF","Eta1_ggF",100,-4,4);
    TH1F *hist_Phi1_ggF=new TH1F("Phi1_ggF","Phi1_ggF",100,-4,4);

    TH1F *hist_M2_ggF=new TH1F("M2_ggF","M2_ggF",100,0,200);
    TH1F *hist_Pt2_ggF=new TH1F("Pt2_ggF","Pt2_ggF",100,0,600000);
    TH1F *hist_Eta2_ggF=new TH1F("Eta2_ggF","Eta2_ggF",100,-4,4);
    TH1F *hist_Phi2_ggF=new TH1F("Phi2_ggF","Phi2_ggF",100,-4,4);

    TH1F *hist_M3_ggF=new TH1F("M3_ggF","M3_ggF",100,0,200);
    TH1F *hist_Pt3_ggF=new TH1F("Pt3_ggF","Pt3_ggF",100,0,600000);
    TH1F *hist_Eta3_ggF=new TH1F("Eta3_ggF","Eta3_ggF",100,-4,4);
    TH1F *hist_Phi3_ggF=new TH1F("Phi3_ggF","Phi3_ggF",100,-4,4);

    TH1F *hist_M4_ggF=new TH1F("M4_ggF","M4_ggF",100,0,200);
    TH1F *hist_Pt4_ggF=new TH1F("Pt4_ggF","Pt4_ggF",100,0,100000);
    TH1F *hist_Eta4_ggF=new TH1F("Eta4_ggF","Eta4_ggF",100,-4,4);
    TH1F *hist_Phi4_ggF=new TH1F("Phi4_ggF","Phi4_ggF",100,-4,4);



     
     

    //Fill the hist

    int id=0;
    //sig

    int num_sig = sig->GetEntries();

    for (int i=0;i<num_sig;i++){
        sig->GetEntry(i);
        
        
        hist_HiggsM_sig->Fill(HiggsM_sig,EventWeight_sig);
        hist_HiggsPt_sig->Fill(HiggsPt_sig,EventWeight_sig);
        hist_HiggsEta_sig->Fill(HiggsEta_sig,EventWeight_sig);
        hist_HiggsR_sig->Fill(HiggsR_sig,EventWeight_sig);
        hist_HiggsPhi_sig->Fill(HiggsPhi_sig,EventWeight_sig);

        hist_M12_sig->Fill(M12_sig,EventWeight_sig);
        hist_Pt12_sig->Fill(Pt12_sig,EventWeight_sig);
        hist_Eta12_sig->Fill(Eta12_sig,EventWeight_sig);
        hist_R12_sig->Fill(R12_sig,EventWeight_sig);
        hist_Phi12_sig->Fill(Phi12_sig,EventWeight_sig);
        hist_DeltaR12_sig->Fill(DeltaR12_sig,EventWeight_sig);

        hist_M34_sig->Fill(M34_sig,EventWeight_sig);
        hist_Pt34_sig->Fill(Pt34_sig,EventWeight_sig);
        hist_Eta34_sig->Fill(Eta34_sig,EventWeight_sig);
        hist_R34_sig->Fill(R34_sig,EventWeight_sig);
        hist_Phi34_sig->Fill(Phi34_sig,EventWeight_sig);
        hist_DeltaR34_sig->Fill(DeltaR34_sig,EventWeight_sig);
        hist_DeltaRZZ_sig->Fill(DeltaRZZ_sig,EventWeight_sig);

        hist_M1_sig->Fill(M1_sig,EventWeight_sig);
        hist_Pt1_sig->Fill(Pt1_sig,EventWeight_sig);
        hist_Eta1_sig->Fill(Eta1_sig,EventWeight_sig);
        hist_Phi1_sig->Fill(Phi1_sig,EventWeight_sig);

        hist_M2_sig->Fill(M2_sig,EventWeight_sig);
        hist_Pt2_sig->Fill(Pt2_sig,EventWeight_sig);
        hist_Eta2_sig->Fill(Eta2_sig,EventWeight_sig);
        hist_Phi2_sig->Fill(Phi2_sig,EventWeight_sig);

        hist_M3_sig->Fill(M3_sig,EventWeight_sig);
        hist_Pt3_sig->Fill(Pt3_sig,EventWeight_sig);
        hist_Eta3_sig->Fill(Eta3_sig,EventWeight_sig);
        hist_Phi3_sig->Fill(Phi3_sig,EventWeight_sig);

        hist_M4_sig->Fill(M4_sig,EventWeight_sig);
        hist_Pt4_sig->Fill(Pt4_sig,EventWeight_sig);
        hist_Eta4_sig->Fill(Eta4_sig,EventWeight_sig);
        hist_Phi4_sig->Fill(Phi4_sig,EventWeight_sig);

        
 


    }

    //NR
    int num_NR = NR->GetEntries();

    for (int i=0;i<num_NR;i++){
        NR->GetEntry(i);
        /*
        if (ElectronsEta_NR->size() > id) hist_ElectronsEta_NR->Fill((*ElectronsEta_NR)[id]);
        if (ElectronsE_NR->size() > id) hist_ElectronsE_NR->Fill((*ElectronsE_NR)[id]);
        if (ElectronsPhi_NR->size() > id) hist_ElectronsPhi_NR->Fill((*ElectronsPhi_NR)[id]);
        if (ElectronsPt_NR->size() > id) hist_ElectronsPt_NR->Fill((*ElectronsPt_NR)[id]);
        if (MuonsEta_NR->size() > id) hist_MuonsEta_NR->Fill((*MuonsEta_NR)[id]);
        if (MuonsPt_NR->size() > id) hist_MuonsPt_NR->Fill((*MuonsPt_NR)[id]);
        if (MuonsE_NR->size() > id) hist_MuonsE_NR->Fill((*MuonsE_NR)[id]);
        if (MuonsPhi_NR->size() > id) hist_MuonsPhi_NR->Fill((*MuonsPhi_NR)[id]);
        if (JetsEta_NR->size() > id) hist_JetsEta_NR->Fill((*JetsEta_NR)[id]);
        if (JetsPt_NR->size() > id) hist_JetsPt_NR->Fill((*JetsPt_NR)[id]);
         */
        
        
            hist_HiggsM_NR->Fill(HiggsM_NR,EventWeight_NR);
            hist_HiggsPt_NR->Fill(HiggsPt_NR,EventWeight_NR);
            hist_HiggsPt_NR->Fill(HiggsPt_NR,EventWeight_NR);
            hist_HiggsEta_NR->Fill(HiggsEta_NR,EventWeight_NR);
            hist_HiggsR_NR->Fill(HiggsR_NR,EventWeight_NR);
            hist_HiggsPhi_NR->Fill(HiggsPhi_NR,EventWeight_NR);

            hist_M12_NR->Fill(M12_NR,EventWeight_NR);
            hist_Pt12_NR->Fill(Pt12_NR,EventWeight_NR);
            hist_Eta12_NR->Fill(Eta12_NR,EventWeight_NR);
            hist_R12_NR->Fill(R12_NR,EventWeight_NR);
            hist_Phi12_NR->Fill(Phi12_NR,EventWeight_NR);
            hist_DeltaR12_NR->Fill(DeltaR12_NR,EventWeight_NR);

            hist_M34_NR->Fill(M34_NR,EventWeight_NR);
            hist_Pt34_NR->Fill(Pt34_NR,EventWeight_NR);
            hist_Eta34_NR->Fill(Eta34_NR,EventWeight_NR);
            hist_R34_NR->Fill(R34_NR,EventWeight_NR);
            hist_Phi34_NR->Fill(Phi34_NR,EventWeight_NR);
            hist_DeltaR34_NR->Fill(DeltaR34_NR,EventWeight_NR);
            hist_DeltaRZZ_NR->Fill(DeltaRZZ_NR,EventWeight_NR);

            hist_M1_NR->Fill(M1_NR,EventWeight_NR);
            hist_Pt1_NR->Fill(Pt1_NR,EventWeight_NR);
            hist_Eta1_NR->Fill(Eta1_NR,EventWeight_NR);
            hist_Phi1_NR->Fill(Phi1_NR,EventWeight_NR);

            hist_M2_NR->Fill(M2_NR,EventWeight_NR);
            hist_Pt2_NR->Fill(Pt2_NR,EventWeight_NR);
            hist_Eta2_NR->Fill(Eta2_NR,EventWeight_NR);
            hist_Phi2_NR->Fill(Phi2_NR,EventWeight_NR);

            hist_M3_NR->Fill(M3_NR,EventWeight_NR);
            hist_Pt3_NR->Fill(Pt3_NR,EventWeight_NR);
            hist_Eta3_NR->Fill(Eta3_NR,EventWeight_NR);
            hist_Phi3_NR->Fill(Phi3_NR,EventWeight_NR);

            hist_M4_NR->Fill(M4_NR,EventWeight_NR);
            hist_Pt4_NR->Fill(Pt4_NR,EventWeight_NR);
            hist_Eta4_NR->Fill(Eta4_NR,EventWeight_NR);
            hist_Phi4_NR->Fill(Phi4_NR,EventWeight_NR);


        



    }


   

    //ggF
    int num_ggF = ggF->GetEntries();

    for (int i=0;i<num_ggF;i++){
        
        ggF->GetEntry(i);
        /*
        if (ElectronsEta_ggF->size() > id) hist_ElectronsEta_ggF->Fill((*ElectronsEta_ggF)[id]);
        if (ElectronsE_ggF->size() > id) hist_ElectronsE_ggF->Fill((*ElectronsE_ggF)[id]);
        if (ElectronsPhi_ggF->size() > id) hist_ElectronsPhi_ggF->Fill((*ElectronsPhi_ggF)[id]);
        if (ElectronsPt_ggF->size() > id) hist_ElectronsPt_ggF->Fill((*ElectronsPt_ggF)[id]);
        if (MuonsEta_ggF->size() > id) hist_MuonsEta_ggF->Fill((*MuonsEta_ggF)[id]);
        if (MuonsPt_ggF->size() > id) hist_MuonsPt_ggF->Fill((*MuonsPt_ggF)[id]);
        if (MuonsE_ggF->size() > id) hist_MuonsE_ggF->Fill((*MuonsE_ggF)[id]);
        if (MuonsPhi_ggF->size() > id) hist_MuonsPhi_ggF->Fill((*MuonsPhi_ggF)[id]);
        if (JetsEta_ggF->size() > id) hist_JetsEta_ggF->Fill((*JetsEta_ggF)[id]);
        if (JetsPt_ggF->size() > id) hist_JetsPt_ggF->Fill((*JetsPt_ggF)[id]);
        */
        
            hist_HiggsM_ggF->Fill(HiggsM_ggF,EventWeight_ggF);
            hist_HiggsPt_ggF->Fill(HiggsPt_ggF,EventWeight_ggF);
            hist_HiggsPt_ggF->Fill(HiggsPt_ggF,EventWeight_ggF);
            hist_HiggsEta_ggF->Fill(HiggsEta_ggF,EventWeight_ggF);
            hist_HiggsR_ggF->Fill(HiggsR_ggF,EventWeight_ggF);
            hist_HiggsPhi_ggF->Fill(HiggsPhi_ggF,EventWeight_ggF);

            hist_M12_ggF->Fill(M12_ggF,EventWeight_ggF);
            hist_Pt12_ggF->Fill(Pt12_ggF,EventWeight_ggF);
            hist_Eta12_ggF->Fill(Eta12_ggF,EventWeight_ggF);
            hist_R12_ggF->Fill(R12_ggF,EventWeight_ggF);
            hist_Phi12_ggF->Fill(Phi12_ggF,EventWeight_ggF);
            hist_DeltaR12_ggF->Fill(DeltaR12_ggF,EventWeight_ggF);

            hist_M34_ggF->Fill(M34_ggF,EventWeight_ggF);
            hist_Pt34_ggF->Fill(Pt34_ggF,EventWeight_ggF);
            hist_Eta34_ggF->Fill(Eta34_ggF,EventWeight_ggF);
            hist_R34_ggF->Fill(R34_ggF,EventWeight_ggF);
            hist_Phi34_ggF->Fill(Phi34_ggF,EventWeight_ggF);
            hist_DeltaR34_ggF->Fill(DeltaR34_ggF,EventWeight_ggF);
            hist_DeltaRZZ_ggF->Fill(DeltaRZZ_ggF,EventWeight_ggF);

            hist_M1_ggF->Fill(M1_ggF,EventWeight_ggF);
            hist_Pt1_ggF->Fill(Pt1_ggF,EventWeight_ggF);
            hist_Eta1_ggF->Fill(Eta1_ggF,EventWeight_ggF);
            hist_Phi1_ggF->Fill(Phi1_ggF,EventWeight_ggF);

            hist_M2_ggF->Fill(M2_ggF,EventWeight_ggF);
            hist_Pt2_ggF->Fill(Pt2_ggF,EventWeight_ggF);
            hist_Eta2_ggF->Fill(Eta2_ggF,EventWeight_ggF);
            hist_Phi2_ggF->Fill(Phi2_ggF,EventWeight_ggF);

            hist_M3_ggF->Fill(M3_ggF,EventWeight_ggF);
            hist_Pt3_ggF->Fill(Pt3_ggF,EventWeight_ggF);
            hist_Eta3_ggF->Fill(Eta3_ggF,EventWeight_ggF);
            hist_Phi3_ggF->Fill(Phi3_ggF,EventWeight_ggF);

            hist_M4_ggF->Fill(M4_ggF,EventWeight_ggF);
            hist_Pt4_ggF->Fill(Pt4_ggF,EventWeight_ggF);
            hist_Eta4_ggF->Fill(Eta4_ggF,EventWeight_ggF);
            hist_Phi4_ggF->Fill(Phi4_ggF,EventWeight_ggF);


        



    }




    
    /*
    int num_NR = NR->GetEntries();
    for (int i=0;i<num_NR;i++){
    NR->GetEntry(i);
    if (ElectronsPt_NR->size() > id) hist_ElectronsPt_NR->Fill((*ElectronsPt_NR)[id]);
    if (ElectronsEta_NR->size() > id) hist_ElectronsEta_NR->Fill((*ElectronsEta_NR)[id]);
    if (ElectronsE_NR->size() > id) hist_ElectronsE_NR->Fill((*ElectronsE_NR)[id]);
    if (MuonsPt_NR->size() > id) hist_MuonsPt_NR->Fill((*MuonsPt_NR)[id]);
    if (MuonsEta_NR->size() > id) hist_MuonsEta_NR->Fill((*MuonsEta_NR)[id]);
    if (MuonsE_NR->size() > id) hist_MuonsE_NR->Fill((*MuonsE_NR)[id]);
    }

    //sig
    int num_sig = sig->GetEntries();
    for (int i=0;i<num_sig;i++){
    sig->GetEntry(i);
    if (ElectronsPt_sig->size() > id) hist_ElectronsPt_sig->Fill((*ElectronsPt_sig)[id]);
    if (ElectronsEta_sig->size() > id) hist_ElectronsEta_sig->Fill((*ElectronsEta_sig)[id]);
    if (ElectronsE_sig->size() > id) hist_ElectronsE_sig->Fill((*ElectronsE_sig)[id]);
    if (MuonsPt_sig->size() > id) hist_MuonsPt_sig->Fill((*MuonsPt_sig)[id]);
    if (MuonsEta_sig->size() > id) hist_MuonsEta_sig->Fill((*MuonsEta_sig)[id]);
    if (MuonsE_sig->size() > id) hist_MuonsE_sig->Fill((*MuonsE_sig)[id]);
    }
    */

    //Draw the picture
    
    TCanvas* CV_M34=new TCanvas("M34","M34 Distribution",800,600);

    //THStack *hs_M34 = new THStack("M34_hs","M34 Distribution");
    gStyle->SetOptStat(0);

    //gStyle->SetPalette(kBlueRedYellow);

    //hist_M34_sig->Scale(1./hist_M34_sig->Integral());

    /*M34ta_sig,*M34_sig,*M34_sig,*M34_sig,*M34_sig,*M34_sig,*MuonsE_sig,*M34_sig,*M34_sig,*M34_sig,*M342_sig,*M342_sig,*M34_sig,*R12_sig,*M342_sig,*M344_sig,*M344_sig,*M34_sig,*R34_sig,*M344_sig,*M34_sig,*M34_sig,*M34_sig,*HiggsR_sig,*M34_sig;*/

    hist_M34_NR->GetXaxis()->SetTitle("MeV");
    hist_M34_NR->GetYaxis()->SetTitle("Arbitrary Unit");
    hist_M34_NR->SetTitle("M34 Distribution");
    hist_M34_sig->GetXaxis()->SetTitle("MeV");
    hist_M34_sig->GetYaxis()->SetTitle("Arbitrary Unit");
    hist_M34_sig->SetTitle("M34 Distribution");
    hist_M34_ggF->GetXaxis()->SetTitle("MeV");
    hist_M34_ggF->GetYaxis()->SetTitle("Arbitrary Unit");
    hist_M34_ggF->SetTitle("M34 Distribution");

    hist_M34_NR->SetLineColor(kBlue);
    hist_M34_NR->DrawNormalized("SAME histo",1);
    hist_M34_sig->SetLineColor(kRed);
    hist_M34_sig->DrawNormalized("SAME histo",1);
    hist_M34_ggF->SetLineColor(kGreen);
    hist_M34_ggF->DrawNormalized("SAME histo",1);

    TLegend leg(.3,.6,.6,.7,"");
    leg.SetFillColor(0);
    leg.AddEntry(&*hist_M34_ggF,"M34_ggF");
    leg.AddEntry(&*hist_M34_NR,"M34_NR");
    leg.AddEntry(&*hist_M34_sig,"M34_sig");
    leg.DrawClone("Same");


    /*
    TCanvas* CV_ElectronsEta=new TCanvas("ElectronsEta","ElectronsEta",800,600);
    TCanvas* CV_ElectronsE=new TCanvas("ElectronsE","ElectronsE",800,600);
    TCanvas* CV_MuonsPt=new TCanvas("MuonsPt","MuonsPt",800,600);
    TCanvas* CV_MuonsEta=new TCanvas("MuonsEta","MuonsEta",800,600);
    TCanvas* CV_MuonsE=new TCanvas("MuonsE","MuonsE",800,600);
    */

    }
