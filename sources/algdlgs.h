//
// FILE: algdlgs.h -- declaration of base classes for all of the algorithm
//                    parameter dialogs
//
// $Id$
//

#ifndef ALGDLGS_H
#define ALGDLGS_H

#include "wx/wx.h"
#include "wxmisc.h"

#include "math/gnumber.h"  

//=========================================================================
//                 dialogAlgorithm: Class declaration
//=========================================================================

class dialogAlgorithm : public guiAutoDialog {
private:
  // Event handlers
  void OnDepth(wxCommandEvent &);
  void OnAll(wxCommandEvent &);
  void OnTrace(wxCommandEvent &);
  void OnOK(wxCommandEvent &);

protected:
  bool m_usesNfg, m_subgames;
  int m_traceDest, m_traceLevel;
  gText m_traceFile;
  wxBoxSizer *m_topSizer;
  wxStaticBoxSizer *m_dominanceBox, *m_subgamesBox, *m_algorithmBox;
  wxRadioBox *m_depthChoice, *m_typeChoice, *m_methodChoice;
  wxCheckBox *m_markSubgames, *m_selectSolutions;

  wxTextCtrl *m_stopAfter;
  wxCheckBox *m_findAll;
  wxRadioBox *m_precision;

  wxString m_stopAfterValue;

  void DominanceFields(bool p_mixed);
  void SubgameFields(void);

  void StopAfterField(void);
  void PrecisionField(void);

  virtual void AlgorithmFields(void) { }
  void MakeCommonFields(bool p_dominance, bool p_subgames, bool p_vianfg);

public:
  dialogAlgorithm(const gText &, bool, wxWindow *parent = 0); 
  virtual ~dialogAlgorithm();

  bool MarkSubgames(void) const 
    { return (m_markSubgames && m_markSubgames->GetValue()); }

  bool Eliminate(void) const
    { return (m_depthChoice->GetSelection() > 0); }
  bool EliminateAll(void) const 
    { return (m_depthChoice->GetSelection() == 2); }
  bool EliminateWeak(void) const
    { return (m_typeChoice->GetSelection() == 0); }
  bool EliminateMixed(void) const
    { return (m_methodChoice && m_methodChoice->GetSelection() == 1); }

  gOutput *TraceFile(void) const;
  int TraceLevel(void) const { return m_traceLevel; }

  virtual gPrecision Precision(void) const { return precDOUBLE; }

  DECLARE_EVENT_TABLE()
};


//=========================================================================
//                      dialogPxi: Class declaration
//=========================================================================

class dialogPxi : public dialogAlgorithm {
protected:
  gText m_defaultPxiFile;
  wxRadioBox *m_plotType;
  wxTextCtrl *m_pxiFile, *m_pxiCommand;
  wxCheckBox *m_runPxi;
  wxStaticBoxSizer *m_pxiBox;

  // Event handlers
  void OnRun(wxCommandEvent &);

  void PxiFields(void);

public:
  dialogPxi(const char *p_label = 0, const char *p_filename = "pxi.out",
	    wxWindow *p_parent = 0);
  virtual ~dialogPxi();

  bool LinearPlot(void) const 
    { return (m_plotType->GetSelection() == 1); }
  gOutput *PxiFile(void) const;
  gText PxiFilename(void) const;
  bool RunPxi(void) const
    { return m_runPxi->GetValue(); }
  gText PxiCommand(void) const;

  DECLARE_EVENT_TABLE()
};

#endif   // ALGDLGS_H

