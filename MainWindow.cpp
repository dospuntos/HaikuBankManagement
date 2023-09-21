#include "MainWindow.h"

#include <Alert.h>
#include <Application.h>
#include <Button.h>
#include <Screen.h>
#include <ScrollView.h>
#include <View.h>

// Message constants
enum
{
	M_ABOUT_REQUESTED = 'abrq',
	M_ADD_RECORD_TO_FILE = 'arcd',
	M_SHOW_RECORD_FROM_FILE = 'srff',
	M_SEARCH_RECORD_IN_FILE = 'srch',
	M_UPDATE_RECORD_ON_FILE = 'updt',
	M_DELETE_RECORD = 'dlte',
};

MainWindow::MainWindow(void)
	:	BWindow(BRect(100,100,400,400),"Bank Management",B_DOCUMENT_WINDOW,
						B_ASYNCHRONOUS_CONTROLS | B_QUIT_ON_WINDOW_CLOSE),
		fAccountQuery()
{
	// Create all the controls for our window.
	BView *back = new BView(Bounds(), "background", B_FOLLOW_ALL, B_WILL_DRAW);
	back->SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	AddChild(back);
	
	// Create Close button
	BButton *close = new BButton(BRect(0,0,1,1), "closebutton", "Close",
					new BMessage(B_QUIT_REQUESTED),
								B_FOLLOW_RIGHT | B_FOLLOW_BOTTOM);
								
	close->ResizeToPreferred();
	close->MoveTo(Bounds().right - 15 - close->Frame().Width(),
					Bounds().bottom - 15 - close->Frame().Height());
	back->AddChild(close);
	close->MakeDefault(true);
	
	// Create About button
	BButton *about = new BButton(BRect(0,0,1,1), "aboutbutton",
						"About" B_UTF8_ELLIPSIS,
						new BMessage(M_ABOUT_REQUESTED),
						B_FOLLOW_LEFT | B_FOLLOW_BOTTOM);
	about->ResizeToPreferred();
	about->MoveTo(close->Frame().left - 15 - about->Frame().Width(),
						Bounds().bottom - 15 - about->Frame().Height());
	back->AddChild(about);
	
	// Create TextView
	BRect r(15,15,Bounds().right - B_V_SCROLL_BAR_WIDTH - 15,
			close->Frame().top - 15);
			
	fTextView = new BTextView(r, "textview",
						r.OffsetToCopy(0,0).InsetByCopy(10,10),
						B_FOLLOW_ALL, B_WILL_DRAW | B_PULSE_NEEDED |
											B_FRAME_EVENTS);
	fTextView->MakeEditable(false);
	
	BScrollView *sv = new BScrollView("scrollview", fTextView, B_FOLLOW_ALL, 0,
										false, true);
	back->AddChild(sv);
	
	
	// Set title
	BString windowTitle;
	status_t status = fAccountQuery.show_data(windowTitle);
	if (status == B_OK)
	{
		SetTitle(windowTitle.String());
	}
	
	// Set textView contents
	BString accountInfo;
	status_t accStatus = fAccountQuery.read_rec(accountInfo);
	if (accStatus == B_OK)
	{
		// Add data to textView
		fTextView->SetText(accountInfo.String());	
	}	
}

void
MainWindow::MessageReceived(BMessage *msg)
{
	switch (msg->what)
	{
		case M_ABOUT_REQUESTED:
		{
			BAlert *alert = new BAlert("Haiku Bank Management",
					"A basic bank management system using C++ and "
					"the Haiku GUI.\n\n", "OK");
			alert->Go();
			break;
		}	
		default:
		{
			BWindow::MessageReceived(msg);
			break;	
		}
	}	
}

void
MainWindow::FrameResized(float w, float h)
{
	// Called whenever the window is resized.
	// TODO	
}

