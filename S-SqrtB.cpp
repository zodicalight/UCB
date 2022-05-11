//
//  S-SqrtB.cpp
//  
//
//  Created by Ronghe Wang on 4/22/22.
//

{
    
#include <vector>
    //None Resonant background
    TChain *NR_ch = new TChain("analysis");
    NR_ch->Add("NR4l.root/analysis");
    NR_ch->Add("NRGG.root/analysis");
    TTree *NR = NR_ch->CopyTree("");
     

    //ggF->Higgs
    TString ggF_path="ggF.root";
    TFile ggF_File(ggF_path.Data(),"ggF");
    TTree *ggF = ggF_File.Get<TTree>("analysis");

    //signal
    TString sig_path="Higgs24ls.root";
    TFile sig_File(sig_path.Data(),"sig");
    TTree *sig = sig_File.Get<TTree>("analysis");



    //Get the variables from root files
    
    vector<float> *ElectronsEta_sig,*ElectronsE_sig,*ElectronsPhi_sig,*ElectronsPt_sig,*MuonsEta_sig,*MuonsPt_sig,*MuonsPhi_sig,*MuonsE_sig,*JetsEta_sig,*JetsPt_sig,*JetsPhi_sig;
    float M12_sig,Pt12_sig,Eta12_sig,R12_sig,Phi12_sig,DeltaR12_sig,M34_sig,Pt34_sig,Eta34_sig,R34_sig,Phi34_sig,DeltaR34_sig,DeltaRZZ_sig;

    vector<float> *ElectronsEta_NR,*ElectronsE_NR,*ElectronsPhi_NR,*ElectronsPt_NR,*MuonsEta_NR,*MuonsPt_NR,*MuonsPhi_NR,*MuonsE_NR,*JetsEta_NR,*JetsPt_NR,*JetsPhi_NR;
    float M12_NR,Pt12_NR,Eta12_NR,R12_NR,Phi12_NR,DeltaR12_NR,M34_NR,Pt34_NR,Eta34_NR,R34_NR,Phi34_NR,DeltaR34_NR,DeltaRZZ_NR;

    vector<float> *ElectronsEta_ggF,*ElectronsE_ggF,*ElectronsPhi_ggF,*ElectronsPt_ggF,*MuonsEta_ggF,*MuonsPt_ggF,*MuonsPhi_ggF,*MuonsE_ggF,*JetsEta_ggF,*JetsPt_ggF,*JetsPhi_ggF;
    float M12_ggF,Pt12_ggF,Eta12_ggF,R12_ggF,Phi12_ggF,DeltaR12_ggF,M34_ggF,Pt34_ggF,Eta34_ggF,R34_ggF,Phi34_ggF,DeltaR34_ggF,DeltaRZZ_ggF;



    float HiggsM_ggF,HiggsPt_ggF,HiggsEta_ggF,HiggsR_ggF,HiggsPhi_ggF;
    float HiggsM_NR,HiggsPt_NR,HiggsEta_NR,HiggsR_NR,HiggsPhi_NR;
    float HiggsM_sig,HiggsPt_sig,HiggsEta_sig,HiggsR_sig,HiggsPhi_sig;
    float EventWeight_ggF,EventWeight_NR,EventWeight_sig;
    
    //float background,signal;
    double S_sqrtB;
    double sig_after = 0, ggF_after = 0, NR_after = 0,S_sqrtB_after;
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
    sig->SetBranchAddress("EventWeight",&EventWeight_sig);
/*
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
 */
        
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
        NR->SetBranchAddress("EventWeight",&EventWeight_NR);
/*
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
 */
        
        
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
    ggF->SetBranchAddress("EventWeight",&EventWeight_ggF);
/*
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
 */
    
    /*
    TTree *newtree = new TTree("analysis","CutTree");
    vector<float> ElectronsEta_new,ElectronsE_new,ElectronsPhi_new,ElectronsPt_new,ElectronsCh_new,MuonsEta_new,MuonsPt_new,MuonsPhi_new,MuonsE_new,MuonsCh_new,JetsEta_new,JetsPt_new,JetsE_new,JetsPhi_new,JetsFlav_new;
    //float EventWeight_new;
    
    float HiggsM_new,HiggsPt_new,HiggsEta_new,HiggsR_new,HiggsPhi_new;
    float M1_new,M2_new,Pt1_new,Pt2_new,Eta1_new,Eta2_new,Phi1_new,Phi2_new,Ch1_new,Ch2_new;
    float M3_new,M4_new,Pt3_new,Pt4_new,Eta3_new,Eta4_new,Phi3_new,Phi4_new,Ch3_new,Ch4_new;
    
    float EventWeight_new;
    */
    //sig
    int Nsig = sig->GetEntries();
    int NggF = ggF->GetEntries();
    int NNR = NR->GetEntries();
    /*
    float BFH2ZZ,BFZ2ls,BFH24ls,CrossSec_cH,CrossSec_ggF,CrossSec_gg2ZZ,CrossSec_ZZ,ItLm;
    BFH2ZZ = 2.619E-02;
    BFH24ls = 2.745E-04;
    BFZ2ls = 0.03632+0.03662; //Br(ee)+Br(uu)
    CrossSec_cH = 0.4503;
    CrossSec_ggF = 48.6+3.78+1.373+0.884+0.507+0.488+0.07425+0.002879+0.0152;//ggF+VBF+WH+ZH+ttH+bbH+tH_tch+tH_sch+tHW
    CrossSec_gg2ZZ = 10.1E-3;
    CrossSec_ZZ = 1.25;
    ItLm = 300000;
    */
    
    float num_sig = 0;
    float num_ggF = 0;
    float num_NNR = 0;
    for (int i = 0; i<Nsig; i++){
        sig->GetEntry(i);
        num_sig = num_sig + EventWeight_sig;
    }
    for (int i = 0; i<NggF; i++){
        ggF->GetEntry(i);
        num_ggF = num_ggF + EventWeight_ggF;
    }
    for (int i = 0; i<NNR; i++){
        NR->GetEntry(i);
        num_NNR = num_NNR + EventWeight_NR;
    }
    
    
    S_sqrtB = num_sig/sqrt(num_ggF + num_NNR); //N_post = sigma * B * L &* E
    cout<<"N of signal"<<num_sig<<endl;
    cout<<"N of background"<<(num_ggF+num_NNR)<<endl;
    cout<<"Before cut "<<S_sqrtB<<endl;
    
    //cuts
    bool truth_sig = FALSE;
    bool truth_ggF = FALSE;
    bool truth_NR = FALSE;
    for (int i=0;i<Nsig;i++){
        sig->GetEntry(i);
       // cout<<HiggsM_sig<<end;
        if ((HiggsM_sig > 100000) && (HiggsM_sig < 130000) && (DeltaRZZ_sig < 2) && (M34_sig < 50000) /*&& (Pt12_sig < 100000)&& (Pt34_sig < 80000)&& (HiggsPt_sig < 100000) && (HiggsEta_sig < 2) && (HiggsEta_sig > -2)*/){
            truth_sig = TRUE;
            if (truth_sig){
                sig_after = sig_after + EventWeight_sig;
            }
        }
    }
    
    for (int i=0;i<NggF;i++){
        ggF->GetEntry(i);
        if ((HiggsM_ggF > 100000) && (HiggsM_ggF < 130000) && (DeltaRZZ_ggF < 2) && (M34_ggF< 50000) /*&& (Pt12_ggF < 100000)&& (Pt34_ggF < 80000)&& (HiggsPt_ggF < 100000) && (HiggsEta_ggF < 2) && (HiggsEta_ggF > -2)*/){
            truth_ggF = TRUE;
            if (truth_ggF){
                ggF_after = ggF_after + EventWeight_ggF;
            }
        }
    }
    for (int i=0;i<NNR;i++){
        NR->GetEntry(i);
        if ((HiggsM_NR > 100000) && (HiggsM_NR < 130000) && (DeltaRZZ_NR < 2) && (M34_NR < 50000) /*&& (Pt12_NR < 100000)&& (Pt34_NR < 80000) && (HiggsPt_NR < 100000) && (HiggsEta_NR < 2) && (HiggsEta_NR > -2)*/){
            truth_NR = TRUE;
            if (truth_NR) {
                NR_after = NR_after + EventWeight_NR;
            }
        }
    }
    
    S_sqrtB_after = (sig_after)/sqrt(NR_after + ggF_after);
    cout<<"N of signal"<<sig_after<<endl;
    cout<<"N of background"<<(NR_after + ggF_after)<<endl;
    cout<<"After cut "<<S_sqrtB_after<<endl;
    
}
        


