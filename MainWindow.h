#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <TextView.h>
#include <Window.h>
#include "AccountQuery.h"

class MainWindow : public BWindow
{
public:
				MainWindow(void);
		void	MessageReceived(BMessage *msg);
		void	FrameResized(float w, float h);
		
private:
		BTextView			*fTextView;
		account_query		fAccountQuery;
};

#endif
