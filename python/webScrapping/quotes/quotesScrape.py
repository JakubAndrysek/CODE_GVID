import requests
from bs4 import BeautifulSoup
from prettytable import PrettyTable


def get_html(url):
    r = requests.get(url)
    if r.status_code == 200:
        return r.text
    return None


def basicDataLoad(page_soap):
    print(page_soap.prettify())  # vypise vsechny tagy

    print("Vypisuje title", page_soap.title)  # vypise title
    print("Vypise jen text title", page_soap.title.text)  # vypise jen text title

    print("Vypisuji vsechny tagy a", page_soap.find_all('a'), )  # vypise vsechny tagy a
    print("Vypisuji prvni tag a", page_soap.find_all('a')[0], )  # vypise prvni tag a
    print("Vypisuji text prvniho tagu a", page_soap.find_all('a')[0].text)  # vypise text prvniho tagu a

    print("Vypisuji vsechny tagy s class header-box",
          page_soap.find_all(class_="header-box"))  # vypise vsechny tagy s class header-box


def quotesList(page_soap):
    quotes = page_soap.find_all("div", class_="quote")

    quotes_list = []
    for quote in quotes:
        quote_text = quote.find("span", class_="text").text
        quote_author = "????? TO DO"
        quote_tags_raw = quote.find("div", class_="tags").find_all("a", class_="tag")
        quote_tags = [tag.text for tag in quote_tags_raw]

        quote_obj = {
            "text": quote_text,
            "author": quote_author,
            "tags": quote_tags
        }
        quotes_list.append(quote_obj)

    return quotes_list


def print_quotes_list(quotes_list):
    table = PrettyTable(["Quote", "Author", "Tags"])
    for quote in quotes_list:
        table.add_row([quote["text"], quote["author"], quote["tags"]])
    print(table)


def get_copyright(raw_html):

    return "????? TO DO"


if __name__ == '__main__':
    url = 'https://quotes.toscrape.com/'
    raw_html = get_html(url)
    page_soap = BeautifulSoup(raw_html, 'html.parser')

    # basicDataLoad(page_soap)
    quotes_list = quotesList(page_soap)
    print_quotes_list(quotes_list)

    copyright = get_copyright(raw_html)
    print("Copyright: ", copyright)
