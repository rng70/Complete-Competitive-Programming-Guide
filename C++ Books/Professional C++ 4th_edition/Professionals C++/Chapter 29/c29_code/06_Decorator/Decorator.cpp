#include <string>
#include <string_view>
#include <iostream>

using namespace std;

class Paragraph
{
public:
	virtual ~Paragraph() = default;  // Always a virtual destructor!

	Paragraph(string_view initialText)
		: mText(initialText)
	{
	}

	virtual string getHTML() const
	{
		return mText;
	}

private:
	string mText;
};

class BoldParagraph : public Paragraph
{
public:
	BoldParagraph(const Paragraph& paragraph)
		: Paragraph(""), mWrapped(paragraph)
	{
	}

	virtual string getHTML() const override
	{
		return "<B>" + mWrapped.getHTML() + "</B>";
	}

private:
	const Paragraph& mWrapped;
};

class ItalicParagraph : public Paragraph
{
public:
	ItalicParagraph(const Paragraph& paragraph)
		: Paragraph(""), mWrapped(paragraph)
	{
	}

	virtual string getHTML() const override
	{
		return "<I>" + mWrapped.getHTML() + "</I>";
	}

private:
	const Paragraph& mWrapped;
};



int main()
{
	Paragraph p("A party? For me? Thanks!");

	// Bold
	cout << BoldParagraph(p).getHTML() << endl;

	// Bold and Italic
	cout << ItalicParagraph(BoldParagraph(p)).getHTML() << endl;

	// Bold and Bold
	cout << BoldParagraph(BoldParagraph(p)).getHTML() << endl;

	return 0;
}
