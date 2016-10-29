import scrapy


class CardapioSpider(scrapy.Spider):
    # Spider Identifier
    name = "cardapiosSAS"

    def start_requests(self):
        # The urls to parse
        urls = ["https://uspdigital.usp.br/rucard/Jsp/cardapioSAS.jsp?codrtn=8"]
        # Get the url and send it into the callback
        for url in urls:
            yield scrapy.Request(url = url, callback=self.parse)

    # Process our response to the desired format
    def parse(self, response):
        # Symbol Table with key - value
        dictRest = {'8':'Física', '9':'Química'}
        # Modify this parse method
        page = dictRest[response.url.split("/")[-1][-1]]
        filename = 'c_%s.html' % page
        with open(filename, mode='wb') as f:
            f.write(response.body)
        self.log('Saved dump file %s' % filename)
