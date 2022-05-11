#include <iostream>
//#include<bits/stdc++.h>
{
  ofstream outfile("erin.txt");
  TChain *ch = new TChain("analysis");
  int opt = 0;
  if (opt == 0){
    //ch->Add("ErinWithoutMassCut.root/analysis");
    //ch->Add("/eos/user/z/zhhuang/URAP/signal/ErinWithMassCut.root/analysis");
    //ch->Add("JuneWithMassCut.root/analysis");
    //ch->Add("/eos/user/z/zhhuang/URAP/signal/cH4l_June_250kEvents_*of2_27Apr22.root");
    //ch->Add("/eos/user/z/zhhuang/URAP/signal/JuneWithMassCut.root/analysis");
    ch->Add("cH4l_June_250kEvents_1of2_27Apr22.root/analysis");
    ch->Add("cH4l_June_250kEvents_2of2_27Apr22.root/analysis");
  }
  else if (opt == 1){
    ch->Add("Ntuple_341471.root/analysis");
  }
  else if (opt == 2){
    ch->Add("Ntuple_345706.root/analysis");
  }
  else if (opt == 3){
    ch->Add("Ntuple_364250.root/analysis");
  }
  TTree *oldtree = ch->CopyTree("");
  delete ch;
    
  vector<float> *ElectronsEta,*ElectronsE,*ElectronsPhi,*ElectronsPt,*ElectronsCh,*MuonsEta,*MuonsPt,*MuonsE,*MuonsPhi,*MuonsCh,*JetsEta,*JetsPt,*JetsE, *JetsPhi,*JetsFlav;
  float EventWeight;
  //float EventWeight;
  oldtree->SetBranchAddress("ElectronsEta",&ElectronsEta);
  oldtree->SetBranchAddress("ElectronsPhi",&ElectronsPhi);
  oldtree->SetBranchAddress("ElectronsE",&ElectronsE);
  oldtree->SetBranchAddress("ElectronsPt",&ElectronsPt);
  oldtree->SetBranchAddress("ElectronsCh",&ElectronsCh);
  oldtree->SetBranchAddress("MuonsEta",&MuonsEta);
  oldtree->SetBranchAddress("MuonsPt",&MuonsPt);
  oldtree->SetBranchAddress("MuonsPhi",&MuonsPhi);
  oldtree->SetBranchAddress("MuonsE",&MuonsE);
  oldtree->SetBranchAddress("MuonsCh",&MuonsCh);
  oldtree->SetBranchAddress("JetsEta",&JetsEta);
  oldtree->SetBranchAddress("JetsPt",&JetsPt);
  oldtree->SetBranchAddress("JetsE",&JetsE);
  oldtree->SetBranchAddress("JetsPhi",&JetsPhi);
  oldtree->SetBranchAddress("JetsFlav",&JetsFlav);
  oldtree->SetBranchAddress("EventWeight",&EventWeight);
    

  //Create a new file to storage the processed tree
  TTree *newtree = new TTree("analysis","CutTree");
  vector<float> ElectronsEta_new,ElectronsE_new,ElectronsPhi_new,ElectronsPt_new,ElectronsCh_new,MuonsEta_new,MuonsPt_new,MuonsPhi_new,MuonsE_new,MuonsCh_new,JetsEta_new,JetsPt_new,JetsE_new,JetsPhi_new,JetsFlav_new;
  //float EventWeight_new;
  vector<float> ElectronsEta_temp,ElectronsE_temp,ElectronsPhi_temp,ElectronsPt_temp,ElectronsCh_temp,MuonsEta_temp,MuonsPt_temp,MuonsPhi_temp,MuonsE_temp,MuonsCh_temp,JetsEta_temp,JetsPt_temp,JetsE_temp,JetsPhi_temp,JetsFlav_temp;
  vector<float> LeptonPt;
    
  float M12,Pt12,Eta12,R12,Phi12,DeltaR12;
  float M34,Pt34,Eta34,R34,Phi34,DeltaR34;
  //add all Delta R
  float DeltaR13,DeltaR14,DeltaR23,DeltaR24,DeltaRZZ;
    
    
  float DeltaR13_temp,DeltaR14_temp,DeltaR23_temp,DeltaR24_temp;
    
  float HiggsM,HiggsPt,HiggsEta,HiggsR,HiggsPhi;
  float M1,M2,Pt1,Pt2,Eta1,Eta2,Phi1,Phi2,Ch1,Ch2;
  float M3,M4,Pt3,Pt4,Eta3,Eta4,Phi3,Phi4,Ch3,Ch4;
    
    
  float M12_temp,Pt12_temp,R12_temp,Phi12_temp,Eta12_temp,DeltaR12_temp,M1_temp,Pt1_temp,Phi1_temp,Eta1_temp,M2_temp,Pt2_temp,Phi2_temp,Eta2_temp;
  float M34_temp,Pt34_temp,R34_temp,Phi34_temp,Eta34_temp,DeltaR34_temp,M3_temp,Pt3_temp,Phi3_temp,Eta3_temp,M4_temp,Pt4_temp,Phi4_temp,Eta4_temp;
  float HiggsM_temp,HiggsPt_temp,HiggsEta_temp,HiggsR_temp,HiggsPhi_temp;
    
  //float HiggsM_reorder,HiggsPt_reorder,HiggsEta_reorder,HiggsR_reorder,HiggsPhi_reorder;
  float M1_reorder,M2_reorder,Pt1_reorder,Pt2_reorder,Eta1_reorder,Eta2_reorder,Phi1_reorder,Phi2_reorder;
  float M3_reorder,M4_reorder,Pt3_reorder,Pt4_reorder,Eta3_reorder,Eta4_reorder,Phi3_reorder,Phi4_reorder;
    
  float EventWeight_new;
    
  float BFH2ZZ,BFZ2ls,BFH24ls,CrossSec_cH,CrossSec_ggF,CrossSec_gg2ZZ,CrossSec_ZZ,ItLm;
  BFH2ZZ = 2.619E-02;
  BFH24ls = 2.745E-04;
  BFZ2ls = 0.03632+0.03662; //Br(ee)+Br(uu)
  CrossSec_cH = 0.4503;
  CrossSec_ggF = 4.858E+01+3.782E+00+1.373E+00+0.8839+5.071E-01+ 4.880E-01+7.425E-02+2.879E-03+1.517E-02;//ggF+VBF+WH+ZH+ttH+bbH+tH_tch+tH_sch+tHW
  // CrossSec_ggF = 48.6+3.78+1.373+0.884+0.507+0.488+0.07425+0.002879+0.0152;//ggF+VBF+WH+ZH+ttH+bbH+tH_tch+tH_sch+tHW
  CrossSec_gg2ZZ = 10.1E-3;
  CrossSec_ZZ = 1.25;
  ItLm = 3000000;
    
  int nEvents = oldtree->GetEntries();
  float sumOld = 0;
  for (int i=0;i<nEvents;i++){
    oldtree->GetEntry(i);
    sumOld = sumOld + EventWeight;
  }
  newtree->Branch("ElectronsEta",&ElectronsEta_new);
  newtree->Branch("ElectronsE",&ElectronsE_new);
  newtree->Branch("ElectronsPhi",&ElectronsPhi_new);
  newtree->Branch("ElectronsPt",&ElectronsPt_new);
  newtree->Branch("ElectronsCh",&ElectronsCh_new);
  newtree->Branch("MuonsEta",&MuonsEta_new);
  newtree->Branch("MuonsPt",&MuonsPt_new);
  newtree->Branch("MuonsE",&MuonsE_new);
  newtree->Branch("MuonsPhi",&MuonsPhi_new);
  newtree->Branch("MuonsCh",&MuonsCh_new);
  newtree->Branch("JetsEta",&JetsEta_new);
  newtree->Branch("JetsPt",&JetsPt_new);
  newtree->Branch("JetsPhi",&JetsPhi_new);
  newtree->Branch("JetsE",&JetsE_new);
  newtree->Branch("JetsFlav",&JetsFlav_new);
  //newtree->Branch("EventWeight",&EventWeight_new);
  newtree->Branch("M12",&M12,"M12/F");
  newtree->Branch("Pt12",&Pt12,"Pt12/F");
  newtree->Branch("Eta12",&Eta12,"Eta12/F");
  newtree->Branch("R12",&R12,"R12/F");
  newtree->Branch("Phi12",&Phi12,"Phi12/F");
  newtree->Branch("DeltaR12",&DeltaR12,"DeltaR12/F");
  newtree->Branch("M34",&M34,"M34/F");
  newtree->Branch("Pt34",&Pt34,"Pt34/F");
  newtree->Branch("Eta34",&Eta34,"Eta34/F");
  newtree->Branch("R34",&R34,"R34/F");
  newtree->Branch("Phi34",&Phi34,"Phi34/F");
  newtree->Branch("DeltaR34",&DeltaR34,"DeltaR34/F");
  newtree->Branch("HiggsM",&HiggsM,"HiggsM/F");
  newtree->Branch("HiggsPt",&HiggsPt,"HiggsPt/F");
  newtree->Branch("HiggsEta",&HiggsEta,"HiggsEta/F");
  newtree->Branch("HiggsR",&HiggsR,"HiggsR/F");
  newtree->Branch("HiggsPhi",&HiggsPhi,"HiggsPhi/F");
    
  newtree->Branch("DeltaR13",&DeltaR12,"DeltaR13/F");
  newtree->Branch("DeltaR14",&DeltaR12,"DeltaR14/F");
  newtree->Branch("DeltaR23",&DeltaR12,"DeltaR23/F");
  newtree->Branch("DeltaR24",&DeltaR12,"DeltaR24/F");
  newtree->Branch("DeltaRZZ",&DeltaRZZ,"DeltaRZZ/F");
    
  newtree->Branch("M1",&M1_reorder,"M1/F");
  newtree->Branch("Pt1",&Pt1_reorder,"Pt1/F");
  newtree->Branch("Eta1",&Eta1_reorder,"Eta1/F");
  newtree->Branch("Phi1",&Phi1_reorder,"Phi1/F");
  newtree->Branch("M2",&M2_reorder,"M2/F");
  newtree->Branch("Pt2",&Pt2_reorder,"Pt2/F");
  newtree->Branch("Eta2",&Eta2_reorder,"Eta2/F");
  newtree->Branch("Phi2",&Phi2_reorder,"Phi2/F");
  newtree->Branch("M3",&M3_reorder,"M3/F");
  newtree->Branch("Pt3",&Pt3_reorder,"Pt3/F");
  newtree->Branch("Eta3",&Eta3_reorder,"Eta3/F");
  newtree->Branch("Phi3",&Phi3_reorder,"Phi3/F");
  newtree->Branch("M4",&M4_reorder,"M4/F");
  newtree->Branch("Pt4",&Pt4_reorder,"Pt4/F");
  newtree->Branch("Eta4",&Eta4_reorder,"Eta4/F");
  newtree->Branch("Phi4",&Phi4_reorder,"Phi4/F");
    
  newtree->Branch("EventWeight",&EventWeight_new);

  double cf0_w = 0.;
  double cf0_u = 0.;
  double cf1_w = 0.;
  double cf1_u = 0.;
  double cf1p5_w = 0.;
  double cf1p5_u = 0.;
  double cf2_w = 0.;
  double cf2_u = 0.;
  double cff_w = 0.;
  double cff_u = 0.;
    
  //Cut Tree
  for (int i = 0; i<nEvents; i++){
    // EventWeight_new = EventWeight * CrossSec_cH * ItLm * BFH24ls / sumOld;
    oldtree->GetEntry(i);

    if (opt == 0) {
      EventWeight_new = EventWeight * CrossSec_cH * ItLm * BFH24ls / sumOld;
    }
    else if (opt == 1) {
      EventWeight_new = EventWeight * CrossSec_ggF * ItLm * BFH24ls / sumOld;
    }
    else if (opt == 2) {
      EventWeight_new = EventWeight * CrossSec_gg2ZZ * ItLm / sumOld;
    }
    else if (opt == 3){
      EventWeight_new = EventWeight * CrossSec_ZZ * ItLm / sumOld;
    }
    
    int nElements_Elec = ElectronsE->size();
    int nElements_Muon = MuonsPt->size();
    int nElements_Jets = JetsPt->size();

    cf0_w+=EventWeight_new;
    cf0_u+=1.;
        
    ElectronsEta_temp.clear();
    ElectronsE_temp.clear();
    ElectronsPhi_temp.clear();
    ElectronsPt_temp.clear();
    ElectronsCh_temp.clear();
    MuonsE_temp.clear();
    MuonsEta_temp.clear();
    MuonsPhi_temp.clear();
    MuonsPt_temp.clear();
    MuonsCh_temp.clear();
    JetsPt_temp.clear();
    JetsEta_temp.clear();
    JetsPhi_temp.clear();
    JetsE_temp.clear();
    JetsFlav_temp.clear();
    ElectronsE_new.clear();
    ElectronsEta_new.clear();
    ElectronsPhi_new.clear();
    ElectronsPt_new.clear();
    ElectronsCh_new.clear();
    MuonsE_new.clear();
    MuonsEta_new.clear();
    MuonsPhi_new.clear();
    MuonsPt_new.clear();
    MuonsCh_new.clear();
    JetsPt_new.clear();
    JetsEta_new.clear();
    JetsPhi_new.clear();
    JetsE_new.clear();
    JetsFlav_new.clear();
    if  ((((nElements_Elec > 1)&&(nElements_Muon > 1))||(nElements_Elec > 3)||(nElements_Muon > 3))&&(nElements_Jets > 0)){
      for (int j = 0; j < nElements_Elec; j++){
        TLorentzVector temp_vector(0,0,0,0);
        temp_vector.SetPtEtaPhiE((*ElectronsPt)[j],(*ElectronsEta)[j],(*ElectronsPhi)[j],(*ElectronsE)[j]);
        if ((abs((*ElectronsEta)[j])<2.47)&&(temp_vector.Et()>7000)) { //Change this to Et
          ElectronsE_temp.push_back((*ElectronsE)[j]);
          ElectronsEta_temp.push_back((*ElectronsEta)[j]);
          ElectronsPhi_temp.push_back((*ElectronsPhi)[j]);
          ElectronsPt_temp.push_back((*ElectronsPt)[j]);
          ElectronsCh_temp.push_back((*ElectronsCh)[j]);
        }
      }
      for (int j = 0; j < nElements_Muon; j++){
        if ((abs((*MuonsEta)[j])<2.7)&&((*MuonsPt)[j]>5000)){
          MuonsPt_temp.push_back((*MuonsPt)[j]);
          MuonsEta_temp.push_back((*MuonsEta)[j]);
          MuonsPhi_temp.push_back((*MuonsPhi)[j]);
          MuonsE_temp.push_back((*MuonsE)[j]);
          MuonsCh_temp.push_back((*MuonsCh)[j]);
        }
      }
      for (int j = 0; j < nElements_Jets; j++){
        if ((abs((*JetsEta)[j])<4)&&((*JetsPt)[j]>30000)){
          JetsPt_new.push_back((*JetsPt)[j]);
          JetsEta_new.push_back((*JetsEta)[j]);
          JetsPhi_new.push_back((*JetsPhi)[j]);
          JetsE_new.push_back((*JetsE)[j]);
          JetsFlav_new.push_back((*JetsFlav)[j]);
        }
      }
      int nElecs = ElectronsPt_temp.size();
      int nMuons = MuonsPt_temp.size();
      int nJets = JetsPt_new.size();
      bool truthcut = true;
      if ((((nElecs > 1)&&(nMuons > 1))||(nElecs > 3)||(nMuons > 3))&&(nJets > 0)) {
        for (int j = 0; j < nJets; j++)
          for (int k =j+1;k < nJets; k++){
            float JetsPt_temp;
            int Flav=0;
            if (JetsPt_new[j]<JetsPt_new[k]) {
              JetsPt_temp = JetsPt_new[j];
              JetsPt_new[j] = JetsPt_new[k];
              JetsPt_new[k] = JetsPt_temp;
              JetsPt_temp = JetsEta_new[j];
              JetsEta_new[j] = JetsEta_new[k];
              JetsEta_new[k] = JetsPt_temp;
              JetsPt_temp = JetsPhi_new[j];
              JetsPhi_new[j] = JetsPhi_new[k];
              JetsPhi_new[k] = JetsPt_temp;
              JetsPt_temp = JetsE_new[j];
              JetsE_new[j] = JetsE_new[k];
              JetsE_new[k] = JetsPt_temp;
              Flav = JetsFlav_new[j];
              JetsFlav_new[j] = JetsFlav_new[k];
              JetsFlav_new[k] = Flav;
            }
          }
        TLorentzVector V1(0,0,0,0);
        TLorentzVector V2(0,0,0,0);
        TLorentzVector LD(0,0,0,0);
        M12 = -10000;
        int LDX = 0; int LDY = 0;
        float ElectronsM = 0.5109989461;
        float MuonsM = 105.6583745;
        TString flag="";
        //M12_temp=-10000;
        for (int j=0;j<nElecs;j++)
          for (int k=j+1;k<nElecs;k++){
            M12_temp=-10000;
            V1.SetPtEtaPhiM(ElectronsPt_temp[j],ElectronsEta_temp[j],ElectronsPhi_temp[j],ElectronsM);
            V2.SetPtEtaPhiM(ElectronsPt_temp[k],ElectronsEta_temp[k],ElectronsPhi_temp[k],ElectronsM);
            LD = V1+V2;
                        
            M12_temp = LD.M(); //mass of lepton pairs M12 > 5000
            Pt12_temp = LD.Pt(); // Define all the values before the if statement
            R12_temp = LD.Rapidity();
            Phi12_temp = LD.Phi();
            Eta12_temp = LD.Eta();
            DeltaR12_temp = V1.DeltaR(V2);
                    
            M1_temp = V1.M();
            Pt1_temp = V1.Pt();
            Phi1_temp = V1.Phi();
            Eta1_temp = V1.Eta();
            Ch1 = ElectronsCh_temp[j];
                    
            M2_temp = V2.M();
            Pt2_temp = V2.Pt();
            Phi2_temp = V2.Phi();
            Eta2_temp = V2.Eta();
            Ch2 = ElectronsCh_temp[k];
            if (((abs(M12_temp-91187.6))<(abs(M12-91187.6)) && (Ch1 == -(Ch2))) /*&& (DeltaR12_temp>0.1) && (50000<M12_temp) && (M12_temp<106000) && (Pt1_temp>20000) && (Pt2_temp>15000) && (abs(M12_temp)>5000) && (Ch1 = -(Ch2))*/){
              //Change to M1 to Pt, and set the values then cuts
              LDX = j; LDY = k;
              M12 = M12_temp;
              Pt12 = Pt12_temp;
              R12 = R12_temp;
              Phi12 =  Phi12_temp;
              Eta12 = Eta12_temp;
              DeltaR12 = DeltaR12_temp;
                        
              M1 = M1_temp;
              Pt1 = Pt1_temp;// Combine DeltaR1 and R2
              Phi1 = Phi1_temp;
              Eta1 = Eta1_temp;
                        
              M2 = M2_temp;
              Pt2 = Pt2_temp;
              Phi2 = Phi2_temp;
              Eta2 = Eta2_temp;
                            
              /*
                M12.push_back(M12_temp);
                Pt12.push_back(Pt12_temp);
                R12.push_back(R12_temp);
                Phi12.push_back(Phi12_temp);
                Eta12.push_back(Eta12_temp);
                DeltaR12.push_back(Delta12_temp);
                M1.push_back(M1_temp);
                Pt1.push_back(Pt1_temp);
                Phi1.push_back(Phi1_temp);
                Eta1.push_back(Eta1_temp);
                M2.push_back(M2_temp);
                Pt2.push_back(Pt2_temp);
                Phi2.push_back(Phi2_temp);
                Eta2.push_back(Eta2_temp);
              */

                        
              flag="Elec";
            }
          }
        //M12_temp=-10000;
        for (int j=0;j<nMuons;j++)
          for (int k=j+1;k<nMuons;k++){
            M12_temp=-10000;
            V1.SetPtEtaPhiM(MuonsPt_temp[j],MuonsEta_temp[j],MuonsPhi_temp[j],MuonsM);
            V2.SetPtEtaPhiM(MuonsPt_temp[k],MuonsEta_temp[k],MuonsPhi_temp[k],MuonsM);
            LD = V1+V2;
                        
            M12_temp = LD.M(); //mass of lepton pairs M12 > 5000
            Pt12_temp = LD.Pt(); // Define all the values before the if statement
            R12_temp = LD.Rapidity();
            Phi12_temp = LD.Phi();
            Eta12_temp = LD.Eta();
            DeltaR12_temp = V1.DeltaR(V2);
                    
            M1_temp = V1.M();
            Pt1_temp = V1.Pt();
            Phi1_temp = V1.Phi();
            Eta1_temp = V1.Eta();
            Ch1 = MuonsCh_temp[j];
                    
            M2_temp = V2.M();
            Pt2_temp = V2.Pt();
            Phi2_temp = V2.Phi();
            Eta2_temp = V2.Eta();
            Ch2 = MuonsCh_temp[k];
            if (((abs(M12_temp-91187.6))<(abs(M12-91187.6)) && (Ch1 == -(Ch2)) /*&& (DeltaR12_temp>0.1) && (50000<M12_temp) && (M12_temp<106000) && (Pt1_temp>20000) && (Pt2_temp>15000) && (abs(M12_temp)>5000) && (Ch1 = -(Ch2))*/)){
              //Change to M1 to Pt, and set the values then cuts
              LDX = j; LDY = k;
              M12 = M12_temp;
              Pt12 = Pt12_temp;
              R12 = R12_temp;
              Phi12 =  Phi12_temp;
              Eta12 = Eta12_temp;
              DeltaR12 = DeltaR12_temp;
                        
              M1 = M1_temp;
              Pt1 = Pt1_temp;
              Phi1 = Phi1_temp;
              Eta1 = Eta1_temp;
                        
              M2 = M2_temp;
              Pt2 = Pt2_temp;
              Phi2 = Phi2_temp;
              Eta2 = Eta2_temp;
              /*M12 = M12_temp;
                MuonsE_new.clear();
                MuonsEta_new.clear();
                MuonsPhi_new.clear();
                MuonsPt_new.clear();
                MuonsE_new.clear();
                MuonsEta_new.clear();
                MuonsPhi_new.clear();
                MuonsPt_new.clear();*/

              /*MuonsE_new.push_back(MuonsE_temp[LDX]);
                MuonsEta_new.push_back(MuonsEta_temp[LDX]);
                MuonsPhi_new.push_back(MuonsPhi_temp[LDX]);
                MuonsPt_new.push_back(MuonsPt_temp[LDX]);
                MuonsE_new.push_back(MuonsE_temp[LDY]);
                MuonsEta_new.push_back(MuonsEta_temp[LDY]);
                MuonsPhi_new.push_back(MuonsPhi_temp[LDY]);
                MuonsPt_new.push_back(MuonsPt_temp[LDY]);*/

              flag="Muon";
            }
          }
        if (flag == "Elec") {
          V1.SetPtEtaPhiM(Pt1,Eta1,Phi1,M1);
          V2.SetPtEtaPhiM(Pt2,Eta2,Phi2,M2);
          ElectronsE_new.push_back(ElectronsE_temp[LDX]);
          ElectronsEta_new.push_back(ElectronsEta_temp[LDX]);
          ElectronsPhi_new.push_back(ElectronsPhi_temp[LDX]);
          ElectronsPt_new.push_back(ElectronsPt_temp[LDX]);
          ElectronsCh_new.push_back(ElectronsCh_temp[LDX]);
          ElectronsE_new.push_back(ElectronsE_temp[LDY]);
          ElectronsEta_new.push_back(ElectronsEta_temp[LDY]);
          ElectronsPhi_new.push_back(ElectronsPhi_temp[LDY]);
          ElectronsPt_new.push_back(ElectronsPt_temp[LDY]);
          ElectronsCh_new.push_back(ElectronsCh_temp[LDY]);
          ElectronsE_temp.erase(ElectronsE_temp.begin()+LDY);
          ElectronsEta_temp.erase(ElectronsEta_temp.begin()+LDY);
          ElectronsPhi_temp.erase(ElectronsPhi_temp.begin()+LDY);
          ElectronsPt_temp.erase(ElectronsPt_temp.begin()+LDY);
          ElectronsCh_temp.erase(ElectronsCh_temp.begin()+LDY);
          ElectronsE_temp.erase(ElectronsE_temp.begin()+LDX);
          ElectronsEta_temp.erase(ElectronsEta_temp.begin()+LDX);
          ElectronsPhi_temp.erase(ElectronsPhi_temp.begin()+LDX);
          ElectronsPt_temp.erase(ElectronsPt_temp.begin()+LDX);
          ElectronsCh_temp.erase(ElectronsCh_temp.begin()+LDX);
                    
          for (int m = 0;m<JetsPt_new.size();m++){
            TLorentzVector Jet(0,0,0,0);
            Jet.SetPtEtaPhiE(JetsPt_new[m],JetsEta_new[m],JetsPhi_new[m],JetsE_new[m]);
            if ((Jet.DeltaR(V1)<0.2) || (Jet.DeltaR(V2)<0.2))
              truthcut=false;
                        
          }
                
                   
        }
        else if (flag == "Muon"){
          V1.SetPtEtaPhiM(Pt1,Eta1,Phi1,M1);
          V2.SetPtEtaPhiM(Pt2,Eta2,Phi2,M2);
          MuonsE_new.push_back(MuonsE_temp[LDX]);
          MuonsEta_new.push_back(MuonsEta_temp[LDX]);
          MuonsPhi_new.push_back(MuonsPhi_temp[LDX]);
          MuonsPt_new.push_back(MuonsPt_temp[LDX]);
          MuonsCh_new.push_back(MuonsCh_temp[LDX]);
          MuonsE_new.push_back(MuonsE_temp[LDY]);
          MuonsEta_new.push_back(MuonsEta_temp[LDY]);
          MuonsPhi_new.push_back(MuonsPhi_temp[LDY]);
          MuonsPt_new.push_back(MuonsPt_temp[LDY]);
          MuonsCh_new.push_back(MuonsCh_temp[LDY]);
          MuonsE_temp.erase(MuonsE_temp.begin()+LDY);
          MuonsEta_temp.erase(MuonsEta_temp.begin()+LDY);
          MuonsPhi_temp.erase(MuonsPhi_temp.begin()+LDY);
          MuonsPt_temp.erase(MuonsPt_temp.begin()+LDY);
          MuonsCh_temp.erase(MuonsCh_temp.begin()+LDY);
          MuonsE_temp.erase(MuonsE_temp.begin()+LDX);
          MuonsEta_temp.erase(MuonsEta_temp.begin()+LDX);
          MuonsPhi_temp.erase(MuonsPhi_temp.begin()+LDX);
          MuonsPt_temp.erase(MuonsPt_temp.begin()+LDX);
          MuonsCh_temp.erase(MuonsCh_temp.begin()+LDX);
                    
          for (int m = 0;m<JetsPt_new.size();m++){
            TLorentzVector Jet(0,0,0,0);
            Jet.SetPtEtaPhiE(JetsPt_new[m],JetsEta_new[m],JetsPhi_new[m],JetsE_new[m]);
            if ((Jet.DeltaR(V1)<0.1) || (Jet.DeltaR(V2)<0.1))
              truthcut=false;
                        
          }

        }
        if(flag=="") continue;
        TLorentzVector V3(0,0,0,0);
        TLorentzVector V4(0,0,0,0);
        TLorentzVector Higgs(0,0,0,0);
        TLorentzVector Sub(0,0,0,0);
        nElecs = ElectronsE_temp.size();
        nMuons = MuonsE_temp.size();
        HiggsM = -10000;
        int SubX = 0; int SubY = 0;
        TString sub_flag="";
        M34 = -10000;
        if (nElecs > 1){
          for (int j=0;j<nElecs;j++)
            for (int k=j+1;k<nElecs;k++){
              M34_temp = -10000;
              V3.SetPtEtaPhiM(ElectronsPt_temp[j],ElectronsEta_temp[j],ElectronsPhi_temp[j],ElectronsM);
              V4.SetPtEtaPhiM(ElectronsPt_temp[k],ElectronsEta_temp[k],ElectronsPhi_temp[k],ElectronsM);
              //Higgs = V1+V2+V3+V4;
              //Sub = V3+V4;
              //if ((abs(Higgs.M()-125250))<(abs(HiggsM-125250))){
              Higgs = V1+V2+V3+V4;
              Sub = V3+V4;
                            
              M34_temp = Sub.M();
              Pt34_temp = Sub.Pt();
              R34_temp = Sub.Rapidity();
              Phi34_temp = Sub.Phi();
              Eta34_temp = Sub.Eta();
              DeltaR34_temp = V3.DeltaR(V4);
              //new delta R
              DeltaR13_temp = V3.DeltaR(V1);
              DeltaR14_temp = V4.DeltaR(V1);
              DeltaR23_temp = V2.DeltaR(V3);
              DeltaR24_temp = V2.DeltaR(V4);
                            
              M3_temp = V3.M();
              Pt3_temp = V3.Pt();
              Phi3_temp = V3.Phi();
              Eta3_temp = V3.Eta();
              Ch3 = ElectronsCh_temp[j];
                            
              M4_temp = V4.M();
              Pt4_temp = V4.Pt();
              Phi4_temp = V4.Phi();
              Eta4_temp = V4.Eta();
                            
              HiggsM_temp = Higgs.M();
              HiggsPt_temp = Higgs.Pt();
              HiggsEta_temp = Higgs.Eta();
              HiggsR_temp = Higgs.Rapidity();
              HiggsPhi_temp = Higgs.Phi();
                            
              Ch4 = ElectronsCh_temp[k];
              if (not (ElectronsCh_temp[j] == -(ElectronsCh_temp[k]))) continue;
              // if (abs(M34_temp-91187.6)<abs(M34-91187.6) or true){
              if (abs(M34_temp-91187.6)<abs(M34-91187.6)){
                //Change to M1 to Pt, and set the values then cuts
        
                SubX = j; SubY = k;
                M34 = M34_temp;
                                
                Pt34 = Pt34_temp;
                R34 = R34_temp;
                Phi34 =  Phi34_temp;
                Eta34 = Eta34_temp;
                DeltaR34 = DeltaR34_temp;
                                
                DeltaR13 = DeltaR13_temp;
                DeltaR14 = DeltaR14_temp;
                DeltaR23 = DeltaR23_temp;
                DeltaR24 = DeltaR24_temp;

                M3 = M3_temp;
                Pt3 = Pt3_temp;// Combine DeltaR3 and R4
                Phi3 = Phi3_temp;
                Eta3 = Eta3_temp;

                M4 = M4_temp;
                Pt4 = Pt4_temp;
                Phi4 = Phi4_temp;
                Eta4 = Eta4_temp;
                                
                HiggsM = HiggsM_temp;
                HiggsPt = HiggsPt_temp;
                HiggsEta = HiggsEta_temp;
                HiggsR =HiggsR_temp;
                HiggsPhi = HiggsPhi_temp;
                                
                sub_flag="Elec";
              }
            }
                    
        }
        if (nMuons > 1){
          //M34_temp=-10000;
          for (int j=0;j<nMuons;j++)
            for (int k=j+1;k<nMuons;k++){
              M34_temp=-10000;
              V3.SetPtEtaPhiM(MuonsPt_temp[j],MuonsEta_temp[j],MuonsPhi_temp[j],MuonsM);
              V4.SetPtEtaPhiM(MuonsPt_temp[k],MuonsEta_temp[k],MuonsPhi_temp[k],MuonsM);

              Higgs = V1+V2+V3+V4;
              Sub = V3+V4;
                            
              M34_temp = Sub.M();
              Pt34_temp = Sub.Pt();
              R34_temp = Sub.Rapidity();
              Phi34_temp = Sub.Phi();
              Eta34_temp = Sub.Eta();
              DeltaR34_temp = V3.DeltaR(V4);
                            
              DeltaR13_temp = V3.DeltaR(V1);
              DeltaR14_temp = V4.DeltaR(V1);
              DeltaR23_temp = V2.DeltaR(V3);
              DeltaR24_temp = V2.DeltaR(V4);
                            
              M3_temp = V3.M();
              Pt3_temp = V3.Pt();
              Phi3_temp = V3.Phi();
              Eta3_temp = V3.Eta();
              Ch3 = MuonsCh_temp[j];
                            
              M4_temp = V4.M();
              Pt4_temp = V4.Pt();
              Phi4_temp = V4.Phi();
              Eta4_temp = V4.Eta();
              Ch4 = MuonsCh_temp[k];
              if (not ((MuonsCh_temp[j] == -(MuonsCh_temp[k])))) continue;
              // if ((((abs(M34_temp-91187.6))<(abs(M34-91187.6)))) or true){
              if ((((abs(M34_temp-91187.6))<(abs(M34-91187.6))))){
                //Change to M1 to Pt, and set the values then cuts
                SubX = j; SubY = k;
                M34 = M34_temp;
                Pt34 = Pt34_temp;
                R34 = R34_temp;
                Phi34 =  Phi34_temp;
                Eta34 = Eta34_temp;
                DeltaR34 = DeltaR34_temp;
                                
                DeltaR13 = DeltaR13_temp;
                DeltaR14 = DeltaR14_temp;
                DeltaR23 = DeltaR23_temp;
                DeltaR24 = DeltaR24_temp;

                M3 = M3_temp;
                Pt3 = Pt3_temp;// Combine DeltaR3 and R4
                Phi3 = Phi3_temp;
                Eta3 = Eta3_temp;

                M4 = M4_temp;
                Pt4 = Pt4_temp;
                Phi4 = Phi4_temp;
                Eta4 = Eta4_temp;
                                
                HiggsM = HiggsM_temp;
                HiggsPt = HiggsPt_temp;
                HiggsEta = HiggsEta_temp;
                HiggsR =HiggsR_temp;
                HiggsPhi = HiggsPhi_temp;
                                
                sub_flag="Muon";
              }
            }
        }
        cf1_w+=EventWeight_new;
        cf1_u+=1.;
        if(sub_flag=="") continue;
        if (sub_flag == "Elec"){
          V3.SetPtEtaPhiM(Pt3,Eta3,Phi3,M3);
          V4.SetPtEtaPhiM(Pt4,Eta4,Phi4,M4);
          ElectronsE_new.push_back(ElectronsE_temp[SubX]);
          ElectronsEta_new.push_back(ElectronsEta_temp[SubX]);
          ElectronsPhi_new.push_back(ElectronsPhi_temp[SubX]);
          ElectronsPt_new.push_back(ElectronsPt_temp[SubX]);
          ElectronsCh_new.push_back(ElectronsCh_temp[SubX]);
          ElectronsE_new.push_back(ElectronsE_temp[SubY]);
          ElectronsEta_new.push_back(ElectronsEta_temp[SubY]);
          ElectronsPhi_new.push_back(ElectronsPhi_temp[SubY]);
          ElectronsPt_new.push_back(ElectronsPt_temp[SubY]);
          ElectronsCh_new.push_back(ElectronsCh_temp[SubY]);
          for (int m = 0;m<JetsPt_new.size();m++){
            TLorentzVector Jet(0,0,0,0);
            Jet.SetPtEtaPhiE(JetsPt_new[m],JetsEta_new[m],JetsPhi_new[m],JetsE_new[m]);
            if ((Jet.DeltaR(V3)<0.2) || (Jet.DeltaR(V4)<0.2))
              truthcut=false;
          }
        }
        else if (sub_flag == "Muon"){
          V3.SetPtEtaPhiM(Pt3,Eta3,Phi3,M3);
          V4.SetPtEtaPhiM(Pt4,Eta4,Phi4,M4);
          MuonsE_new.push_back(MuonsE_temp[SubX]);
          MuonsEta_new.push_back(MuonsEta_temp[SubX]);
          MuonsPhi_new.push_back(MuonsPhi_temp[SubX]);
          MuonsPt_new.push_back(MuonsPt_temp[SubX]);
          MuonsCh_new.push_back(MuonsCh_temp[SubX]);
          MuonsE_new.push_back(MuonsE_temp[SubY]);
          MuonsEta_new.push_back(MuonsEta_temp[SubY]);
          MuonsPhi_new.push_back(MuonsPhi_temp[SubY]);
          MuonsPt_new.push_back(MuonsPt_temp[SubY]);
          MuonsCh_new.push_back(MuonsCh_temp[SubY]);
          for (int m = 0;m<JetsPt_new.size();m++){
            TLorentzVector Jet(0,0,0,0);
            Jet.SetPtEtaPhiE(JetsPt_new[m],JetsEta_new[m],JetsPhi_new[m],JetsE_new[m]);
            if ((Jet.DeltaR(V3)<0.1) || (Jet.DeltaR(V4)<0.1))
              truthcut=false;

          }
          cf1p5_w+=EventWeight_new;
          cf1p5_u+=1.;
        }
        cf2_w+=EventWeight_new;
        cf2_u+=1.;
        Higgs = V1+V2+V3+V4;
        HiggsM = Higgs.M();
        LD = V1+V2;
        Sub = V3+V4;
        DeltaRZZ = (LD).DeltaR(Sub);

        float arr[4] = {};
        arr[0] = Pt1;
        arr[1] = Pt2;
        arr[2] = Pt3;
        arr[3] = Pt4;
                
        //float arr[4] = {Pt1, Pt2, Pt3, Pt4};
        //arr.sort();
        int n = sizeof(arr)/sizeof(arr[0]);
        sort(arr,arr+n,greater<float>());
        int i1 = 0;
        while (i1 < n)
          {
            if (arr[i1] == Pt1) {
              break;
            }
            i1++;
          }

        int i2 = 0;
        while (i2 < n)
          {
            if (arr[i2] == Pt2) {
              break;
            }
            i2++;
          }

                
        int i3 = 0;
        while (i3 < n)
          {
            if (arr[i3] == Pt3) {
              break;
            }
            i3++;
          }

                
        int i4 = 0;
        while (i4 < n)
          {
            if (arr[i4] == Pt4) {
              break;
            }
            i4++;
          }
                
        Pt1_reorder = arr[0];
        Pt2_reorder = arr[1];
        Pt3_reorder = arr[2];
        Pt4_reorder = arr[3];
                
        arr[0] = M1;
        arr[1] = M2;
        arr[2] = M3;
        arr[3] = M4;
                
        M1_reorder = arr[i1];
        M2_reorder = arr[i2];
        M3_reorder = arr[i3];
        M4_reorder = arr[i4];
                
        arr[0] = Phi1;
        arr[1] = Phi2;
        arr[2] = Phi3;
        arr[3] = Phi4;
                
        Phi1_reorder = arr[i1];
        Phi2_reorder = arr[i2];
        Phi3_reorder = arr[i3];
        Phi4_reorder = arr[i4];
                
        arr[0] = Eta1;
        arr[1] = Eta2;
        arr[2] = Eta3;
        arr[3] = Eta4;
                
        Eta1_reorder = arr[i1];
        Eta2_reorder = arr[i2];
        Eta3_reorder = arr[i3];
        Eta4_reorder = arr[i4];
                
        if ((DeltaR12>0.1) && (M12>50000) && (M12<106000) && (Pt1_reorder>20000) && (Pt2_reorder>15000) && (abs(M12)>5000) && truthcut){
          if ((DeltaR34>0.1) && (DeltaR13 > 0.1) && (DeltaR14 > 0.1) && (DeltaR23 > 0.1) && (DeltaR24 > 0.1)&& /*(50000<M34_temp) && (M34<106000) && */ (Pt3_reorder>10000) && (abs(M34)>5000) && (M34 < 115000)){
            if (JetsFlav_new[0] ==4) {EventWeight_new = EventWeight_new * 0.27;}
            else if (JetsFlav_new[0] ==5) {EventWeight_new = EventWeight_new * 0.08;}
            else {EventWeight_new = EventWeight_new* 0.016;}
            // std::cout<<"EventWeight = "<<EventWeight_new<<std::endl;
            cff_w+=EventWeight_new;
            cff_u+=1.;
            newtree->Fill();
            outfile<<i<<" "<<HiggsM<<endl;
          }
        }
                
      }//((((nElecs > 1)&&(nMuons > 1))||(nElecs > 3)||(nMuons > 3))&&(nElements_Jets > 0))
    }//((((nElements_Elec > 1)&&(nElements_Muon > 1))||(nElements_Elec > 3)||(nElements_Muon > 3))&&(nElements_Jets > 0)){
  }//for (int i = 0; i<nEvents; i++)
  //Write the data into a root file
  TFile *newfile;
  if (opt == 0) {
    newfile = TFile::Open("Higgs24ls.root","recreate");}
  else if (opt == 1){
    newfile = TFile::Open("ggF.root","recreate");}
  else if (opt == 2){
    newfile = TFile::Open("NRGG.root","recreate");}
  else if (opt == 3){
    newfile = TFile::Open("NR4l.root","recreate");}
  newtree->Write();
  newfile->Close();
  outfile.close();
/*
  std::cout<<"cf0_w = "<<cf0_w<<std::endl;
  std::cout<<"cf0_u = "<<cf0_u<<std::endl;
  std::cout<<"cf1_w = "<<cf1_w<<std::endl;
  std::cout<<"cf1_u = "<<cf1_u<<std::endl;
  std::cout<<"cf1p5_w = "<<cf1p5_w<<std::endl;
  std::cout<<"cf1p5_u = "<<cf1p5_u<<std::endl;
  std::cout<<"cf2_w = "<<cf2_w<<std::endl;
  std::cout<<"cf2_u = "<<cf2_u<<std::endl;
  std::cout<<"cff_w = "<<cff_w<<std::endl;
  std::cout<<"cff_u = "<<cff_u<<std::endl;
 */
}


            

