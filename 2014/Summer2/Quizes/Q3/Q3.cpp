#include <iostream>
#include <string>
using namespace std;

class Application {
private:
	string name;
	float price;
public:
	Application* left = NULL;
	Application* right = NULL;
	Application(){}
	Application(string name, float price) {
		setName(name);
		setPrice(price);
	}
	void setPrice(float p) {
		price = p;
	}
	float getPrice() {
		return price;
	}
	void setName(string n) {
		name = n;
	}
	string getName() {
		return name;
	}
	virtual float getIncome() = 0;
	virtual void display() {
		cout << "Application" << endl;
		cout << "Name: " << name << endl;
	}
};

class WebApplication : public Application {
private:
	string url;
	float subscribers;
	float monthlyCost;
public:
	WebApplication(){}
	WebApplication(string name, float price, string url, float subscribers, float monthlyCost)
		: Application(name, price)
	{
		this->url = url;
		setSubscribers(subscribers);
		setMonthlyCost(monthlyCost);
	}
	void setUrl(string url) { this->url = url; }
	void setSubscribers(float subscribers) { this->subscribers = subscribers; }
	void setMonthlyCost(float monthlyCost) { this->monthlyCost = monthlyCost; }
	string getUrl() { return url; }
	float getSubscribers() { return subscribers; }
	float getMonthlyCost() { return monthlyCost; }
	float getIncome() {
		return subscribers * monthlyCost;
	}
	void display() {
		Application::display();
		cout << "Web Application" << endl;
		cout << "Subscribers: " << subscribers << "\tMonthly Cost: $" << monthlyCost << endl;
	}
};

class DesktopApplication : public Application {
private:
	float licenses;
	float licenseCost;
public:
	DesktopApplication(){}
	DesktopApplication(string name, float price, float licenses, float licenseCost)
		: Application(name, price)
	{
		setLicenseCost(licenseCost);
		setLicenses(licenses);
	}
	void setLicenses(float licenses) { this->licenses = licenses; }
	void setLicenseCost(float cost) { this->licenseCost = cost; }
	float getLicenses() { return licenses; }
	float getLicenseCost() { return licenseCost; }
	float getIncome() {
		return licenseCost * licenses;
	}
	void display() {
		Application::display();
		cout << "Licenses: " << licenses << "\tLicense Cost: $" << licenseCost << endl;
	}
};

class AppStore {
private:
	Application* root = NULL;
	Application* findCheapest(Application* root) {
		if (root == NULL) return NULL;
		cout << root->getName() << " " << root->getPrice() << endl;
		if (root->left == NULL && root->right == NULL)
			return root;
		Application* cheapestLeft  = findCheapest(root->left);
		Application* cheapestRight = findCheapest(root->right);
		if (cheapestRight == NULL) return cheapestLeft;
		if (cheapestLeft == NULL) return cheapestRight;
		if (cheapestLeft->getPrice() < cheapestRight->getPrice())
			return cheapestLeft;
	}
	void displayInOrder(Application* root) {
		if (root == NULL) return;
		displayInOrder(root->left);
		root->display();
		displayInOrder(root->right);
	}
	void insert(Application** root, Application* app) {
		if (*root == NULL) {
			*root = app;
			return;
		}
		if (app->getName() >= (*root)->getName())
			insert(&((*root)->right), app);
		else if (app->getName() < (*root)->getName())
			insert(&((*root)->left), app);
	}
	float getTotalValue(Application* root) {

	}
public:
	AppStore(){}
	AppStore(Application* root) { this->root = root; }
	void displayInOrder() {
		displayInOrder(root);
	}
	void insert(Application* app) {
		insert(&root, app);
	}
	Application* findCheapest() {
		return findCheapest(root);
	}
};

int main() {
	DesktopApplication* app1 = new DesktopApplication("App1", 21, 12, 23);
	DesktopApplication* app2 = new DesktopApplication("App2", 43, 23, 34);

	WebApplication* app3 = new WebApplication("App3", 54, "abc.com",  32, 43);
	WebApplication* app4 = new WebApplication("App4", 65, "acme.com", 54, 65);
	WebApplication* app5 = new WebApplication("App5", 34, "abc.com",  32, 43);
	WebApplication* app6 = new WebApplication("App6", 17, "acme.com", 54, 65);

	DesktopApplication* app7 = new DesktopApplication("App7", 19, 23, 34);

	AppStore* store = new AppStore();
	store->insert(app4);
	store->insert(app2);
	store->insert(app1);
	store->insert(app3);
	store->insert(app6);
	store->insert(app5);
	store->insert(app7);

	store->displayInOrder();

	Application* cheapest = store->findCheapest();
	if (cheapest != NULL) {
		cout << "Cheapest:" << endl;
		cheapest->display();
	} else {
		cout << "Not found" << endl;
	}
}
