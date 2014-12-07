#include <iostream>
#include <string>
using namespace std;

class Widget {
protected:
	string htmlId;
	string htmlClass;
	string htmlStyle;
	string htmlName;
public:
	Widget(){}
	Widget(string id, string clazz, string style, string name)
	{
		htmlClass = clazz;
		htmlId = id;
		htmlName = name;
		htmlStyle = style;
	}
	Widget(const Widget& other) {
		this->htmlClass = other.htmlClass;
		this->htmlId = other.htmlId;
		this->htmlName = other.htmlName;
		this->htmlStyle = other.htmlStyle;
	}
	void setHtmlClass(string clazz) { this->htmlClass = clazz; }
	void setHtmlName(string name) { this->htmlName = name; }
	void setHtmlId(string id) { htmlId = id; }
	void setHtmlStyle(string style) { htmlStyle = style; }
	string getHtmlClass() { return htmlClass; }
	string getHtmlName() { return htmlName; }
	string getHtmlId() { return htmlId; }
	virtual string renderHtml() = 0;
};

class YouTubeWidget : public Widget {
protected:
	string url;
	int height;
	int width;
public:
	YouTubeWidget(){}
	YouTubeWidget(string name) {
		htmlName = name;
	}
	YouTubeWidget(string id, string clazz, string style, string name, string url, int h, int w)
		: Widget(id, clazz, style, name)
	{
		this->url = url;
		this->width = w;
		this->height = h;
	}
	YouTubeWidget(const YouTubeWidget & other) {
		url = other.url;
		width = other.width;
		height = other.height;
	}
	string renderHtml() {
		cout << htmlName << endl;
	}
};

class HtmlWidget : public Widget {
protected:
	string rawHtml;
public:
	HtmlWidget(string name) {
		htmlName = name;
	}
	HtmlWidget(){}
	HtmlWidget(string id, string clazz, string style, string name, string rawHtml)
		: Widget(id, clazz, style, name)
	{
		this->rawHtml = rawHtml;
	}
	HtmlWidget(const HtmlWidget & other)
	{
		rawHtml = other.rawHtml;
	}
	string renderHtml() {
		cout << htmlName << endl;
	}
};

class FormWidget : public Widget {
protected:
	string name;
	string action;
	string method;
public:
	string renderHtml() {
		cout << htmlName << endl;
	}
	FormWidget(){}
	FormWidget(string name) {
		htmlName = name;
	}
	FormWidget(string id, string clazz, string style, string hname, string name, string action, string method)
		: Widget(id, clazz, style, hname)
	{
		this->name = name; this->action = action; this->method = method;
	}
	FormWidget(const FormWidget & other)
	{
		name = other.name;
		action = other.action;
		method = other.method;
	}
};

int main() {
	YouTubeWidget * y1 = new YouTubeWidget("y1");
	YouTubeWidget * y2 = new YouTubeWidget("y2");
	YouTubeWidget * y3 = new YouTubeWidget("y3");
	YouTubeWidget * y4 = new YouTubeWidget("y4");

	FormWidget * f1 = new FormWidget("f1");
	FormWidget * f2 = new FormWidget("f2");
	FormWidget * f3 = new FormWidget("f3");

	HtmlWidget * w1 = new HtmlWidget("h1");
	HtmlWidget * w2 = new HtmlWidget("h2");
	HtmlWidget * w3 = new HtmlWidget("h3");

	Widget * widgets[] = {w1, w2, w3, f1, f2, f3, y1, y2, y3, y4};

	for (int i = 0; i < 10; i++)
	{
		widgets[i]->renderHtml();
	}
}