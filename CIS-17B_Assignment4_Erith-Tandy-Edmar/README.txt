
Main window buttons will all try functions through User. 
	If User is null or isn't connected, report "NO USER"

User holds a checkings and a savings account.
All slots to open these windows will be in User.

Savings and Checkings classes will hold a function to create a window class they hold.

	e.g.if main window hits switchSavings, it will check for a User slot to for the button,
	which will call its Savings to open the window.

<Tandy> 2017-03-30
-Project and all files inside of it have been organized.
	-Old obsolete code that has been commented out and caused the program to crash or not build/compile has been removed.
	-Lines and blocks of code have been moved around inside of the same body to better group them with labeling.
	-Some variables, functions, and classes have been renamed to better label themselves.
	-Class Account has been edited to have correct functionality when new accounts are created:
		-Account public static int accountNumber variable has been renamed to accounts.
		-New Account private int accountNumber has been created to replace the old one.
		-Account::Account() has been edited so that accounts now increments.
		-Account::Account() has been edited so that accountNumber is now assigned to accounts upon instantiation to keep an accurate count of account number.
		
*For whatever reason, the main window is oversized again. I probably messed something up while cleaning up, and made it bigger than it was before.
	*I didn't figure out how to change it back, so I tried syncing to roll back my changes after saving to a separate location for backup, but the sync wouldn't work.
	*My committ will have this larger main window, which I'm assuming will be an easy fix.
</Tandy>
<Edmar>
transaction class added and need implementation
its working currently link with windows
</Edmar>
use cntrl + / to do block comment its very usefull
