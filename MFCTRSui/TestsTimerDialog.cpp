// TestsTimerDialog.cpp : implementation file
//

#include "stdafx.h"
#include "TestsTimerDialog.h"
#include "afxdialogex.h"
#include "Clock.h"

#include <list>
#include <vector>
// TestsTimerDialog dialog
CListCtrl* List;
IMPLEMENT_DYNAMIC(TestsTimerDialog, CDialogEx)

TestsTimerDialog::TestsTimerDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(TestsTimerDialog::IDD, pParent)
{

}

TestsTimerDialog::~TestsTimerDialog()
{
}

void TestsTimerDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	DDX_Control(pDX, IDC_BUTTON1, m_ButtonAdd);
	DDX_Control(pDX, IDC_BUTTON2, m_ButtonEdit);
	DDX_Control(pDX, IDC_BUTTON3, m_ButtonRemove);
}

BOOL TestsTimerDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CRect rect;
	m_ListCtrl.GetClientRect(&rect);
	int nColInterval = rect.Width() / 4;

	m_ListCtrl.InsertColumn(0, _T("Name"), LVCFMT_LEFT, nColInterval);
	m_ListCtrl.InsertColumn(1, _T("Time"), LVCFMT_LEFT, nColInterval);
	m_ListCtrl.InsertColumn(2, _T("Days"), LVCFMT_LEFT, nColInterval);
	m_ListCtrl.InsertColumn(3, _T("Repeat"), LVCFMT_LEFT, rect.Width() - 3 * nColInterval);



	return true;
}

BEGIN_MESSAGE_MAP(TestsTimerDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &TestsTimerDialog::OnAddClicked)
	ON_BN_CLICKED(IDC_BUTTON2, &TestsTimerDialog::OnEditClicked)
	ON_BN_CLICKED(IDC_BUTTON3, &TestsTimerDialog::OnRemoveClicked)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &TestsTimerDialog::OnListItemchanged)
END_MESSAGE_MAP()


// TestsTimerDialog message handlers


void TestsTimerDialog::OnAddClicked()
{

	if (clock_dlg.DoModal() == IDCANCEL)
		return;
	int size = clock_dlg.get_clock_collection().size();
	
	AddToList(clock_dlg.get_clock_name(), clock_dlg.get_hour(), clock_dlg.get_minute(), clock_dlg.is_weekly(), clock_dlg.get_clock_collection());
}

void TestsTimerDialog::AddToList(CString clock_name, CString hour, CString minute, bool repeat, std::list<Clock> clocks)
{
	DWORD days = 0;
	for (auto i = clocks.begin(); i != clocks.end(); ++i)
	{
		days |= i->get_time().get_day();
	}

	LVITEM lvi;
	CString strItem;
	
	lvi.mask =  LVIF_TEXT;
	strItem.Format(_T("%s"), clock_name);
	lvi.iItem = m_ListCtrl.GetItemCount();
	lvi.iSubItem = 0;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	m_ListCtrl.InsertItem(&lvi);

	strItem.Format(_T("%s:%s"), hour, minute);
	lvi.iSubItem = 1;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	m_ListCtrl.SetItem(&lvi);

	strItem.Format(_T("%s"), GetDayByIndex(days));
	lvi.iSubItem = 2;
	lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
	m_ListCtrl.SetItem(&lvi);

	if (repeat)
	{
		strItem.Format(_T("%s"), "X");
		lvi.iSubItem = 3;
		lvi.pszText = (LPTSTR)(LPCTSTR)(strItem);
		m_ListCtrl.SetItem(&lvi);
	}
}


void TestsTimerDialog::OnEditClicked()
{
	// TODO: Add your control notification handler code here
}


void TestsTimerDialog::OnRemoveClicked()
{
	// TODO: Add your control notification handler code here
}


void TestsTimerDialog::OnListItemchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	POSITION pos = m_ListCtrl.GetFirstSelectedItemPosition();
	
	*pResult = 0;
}

void TestsTimerDialog::UpdateControls(POSITION pos)
{
	if (pos == NULL)
	{
		selection = -1;
		m_ButtonAdd.EnableWindow(false);
		m_ButtonRemove.EnableWindow(false);
	}
	else
	{
		selection = (int)pos;
		m_ButtonAdd.EnableWindow();
		m_ButtonRemove.EnableWindow();
	}
}

CString TestsTimerDialog::GetDayByIndex(int day)
{
	CString ret_str = L"";
	CString day_to_str;

	if (day & 1)
	{
		day_to_str.Format(_T("%s "), _T("Mn"));
		ret_str += day_to_str;
	}
	if (day & 2)
	{
		day_to_str.Format(_T("%s "), _T("Ts"));
		ret_str += day_to_str;
	}
	if (day & 4)
	{
		day_to_str.Format(_T("%s "), _T("Wd"));
		ret_str += day_to_str;
	}
	if (day & 8)
	{
		day_to_str.Format(_T("%s "), _T("Th"));
		ret_str += day_to_str;
	}
	if (day & 16)
	{
		day_to_str.Format(_T("%s "), _T("Fr"));
		ret_str += day_to_str;
	}
	if (day & 32)
	{
		day_to_str.Format(_T("%s "), _T("St"));
		ret_str += day_to_str;
	}
	if (day & 64)
	{
		day_to_str.Format(_T("%s "), _T("Sn"));
		ret_str += day_to_str;
	}

	return ret_str;
}