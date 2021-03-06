#include"pch.h"
#include "XmlParser.h"
int main()
{
	bool exit = false, result = false;
	char choose = '\0';
	char buffer1[256];
	char buffer2[256];
	char buffer3[256];
	XmlParser* xmlParser = new XmlParser();
	char* val = NULL, *text = NULL;
	int n = 0;


	while (!exit) {
		cin.clear();
		cout << "\n\n<Menu>\n-----------------------" << endl;
		cout << "0. Open" << endl;
		cout << "1. Print" << endl;
		cout << "2. Select <id> <key>" << endl;
		cout << "3. Set <id> <key> <value>" << endl;
		cout << "4. Children <id>" << endl;
		cout << "5. Child <id> <n>" << endl;
		cout << "6. Text <id>" << endl;
		cout << "7. Delete <id> <key>" << endl;
		cout << "8. Newchild <id>" << endl;
		cout << "9. XPath <id> <XPath>" << endl;
		cout << "Q. Quit." << endl;

		cout << "Choose an option and press enter: ";
		cin >> choose;

		switch (choose) {
		case '0':
			for (int i = 0; i < 256; i++) buffer1[i] = '\0';
			cin.clear();
			cout << "\nEnter path to file: ";
			cin >> buffer1;
			xmlParser->load(buffer1);
			break;
		case '1':
			xmlParser->print();
			break;
		case '2':
			for (int i = 0; i < 256; i++) buffer1[i] = '\0';
			cin.clear();
			cout << "\nEnter id: ";
			cin >> buffer1;
			for (int i = 0; i < 256; i++) buffer2[i] = '\0';
			cin.clear();
			cout << "\nEnter key: ";
			cin >> buffer2;
			val = xmlParser->getValue(buffer1, buffer2);
			if (val != NULL) {
				cout << "\nResult: <" << val << ">" << endl;
			}
			else {
				cout << "\nCould not find any matches." << endl;
			}
			break;
		case '3':
			for (int i = 0; i < 256; i++) buffer1[i] = '\0';
			cin.clear();
			cout << "\nEnter id: ";
			cin >> buffer1;
			for (int i = 0; i < 256; i++) buffer2[i] = '\0';
			cin.clear();
			cout << "\nEnter key: ";
			cin >> buffer2;
			for (int i = 0; i < 256; i++) buffer3[i] = '\0';
			cin.clear();
			cout << "\nEnter value: ";
			cin >> buffer3;

			if (xmlParser->setAttributeValue(buffer1, buffer2, buffer3) == true) {
				cout << "\nSuccess." << endl;
			}
			else {
				cout << "\nCould not find any matches." << endl;
			}
			break;
		case '4':
			for (int i = 0; i < 256; i++) buffer1[i] = '\0';
			cin.clear();
			cout << "\nEnter id: ";
			cin >> buffer1;

			xmlParser->printChildrenAttributes(buffer1);
			break;
		case '5':
			for (int i = 0; i < 256; i++) buffer1[i] = '\0';
			cin.clear();
			cout << "\nEnter id: ";
			cin >> buffer1;

			cin.clear();
			cout << "\nEnter n: ";
			cin >> n;

			if (xmlParser->getChild(buffer1, n) != NULL) {
				cout << "\nChild found." << endl;
			}
			else {
				cout << "\nCould not find any matches." << endl;
			}
			break;
		case '6':
			for (int i = 0; i < 256; i++) buffer1[i] = '\0';
			cin.clear();
			cout << "\nEnter id: ";
			cin >> buffer1;
			text = xmlParser->getText(buffer1);
			if (text != NULL) {
				cout << "\nText:\n" << text << endl;
			}
			else {
				cout << "\nCould not find any matches." << endl;
			}
			break;
		case '7':
			for (int i = 0; i < 256; i++) buffer1[i] = '\0';
			cin.clear();
			cout << "\nEnter id: ";
			cin >> buffer1;
			for (int i = 0; i < 256; i++) buffer2[i] = '\0';
			cin.clear();
			cout << "\nEnter key: ";
			cin >> buffer2;
			result = xmlParser->deleteAttribute(buffer1, buffer2);
			if (result) {
				cout << "\Success." << endl;
			}
			else {
				cout << "\nCould not find any matches." << endl;
			}

			break;
		case '8':
			for (int i = 0; i < 256; i++) buffer1[i] = '\0';
			cin.clear();
			cout << "\nEnter id: ";
			cin >> buffer1;
			for (int i = 0; i < 256; i++) buffer2[i] = '\0';
			cin.clear();
			cout << "\nEnter key: ";
			cin >> buffer2;
			result = xmlParser->addChild(buffer1, buffer2);
			if (result) {
				cout << "\Success." << endl;
			}
			else {
				cout << "\nCould not find any matches." << endl;
			}

			break;
		case '9':
			break;
		case 'Q':
		case 'q':
			exit = true;
			break;
		default:
			cout << "Invalid option. Please try again." << endl;
		}
	}

	delete xmlParser;
	return 0;
}