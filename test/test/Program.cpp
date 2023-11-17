#include "LoginForm.h"
#include "RegisterForm.h"
#include "WorkForm.h"
#include "GuestForm.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	User^ user = nullptr;
	bool btnGuestPressed = false;
	while (true) {
		test::LoginForm loginForm;
		loginForm.ShowDialog();

		if (loginForm.switchToRegister) {
			test::RegisterForm registerForm;
			registerForm.ShowDialog();

			if (registerForm.switchToLogin) {
				continue;
			}
			else {
				user = registerForm.user;
				break;
			}
		}
		else {
			user = loginForm.user;
			btnGuestPressed = loginForm.btnGuestPressed;
			break;
		}
	}

	if (user != nullptr) {
		test::WorkForm workForm;
		switch (user->authentication) {
			case 2: {
				MessageBox::Show("Welcome " + user->name, "bruh", MessageBoxButtons::OK);
				test::WorkForm workForm;
				Application::Run(% workForm);
				break;
			}
			case 1: {
				MessageBox::Show("Welcome " + user->name, "bruh", MessageBoxButtons::OK);
				test::WorkForm workForm;
				Application::Run(% workForm);
				break;
			}
			case 0: {
				MessageBox::Show("Welcome guest " + user->name, "bruh", MessageBoxButtons::OK);
				test::GuestForm guestForm;
				Application::Run(% guestForm);
			}
		}
	}
	else if (btnGuestPressed) {
		test::GuestForm guestForm;
		Application::Run(% guestForm);
	}
}