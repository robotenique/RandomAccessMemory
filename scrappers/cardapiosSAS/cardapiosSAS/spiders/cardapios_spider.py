#!/usr/bin/env python

"""cardapios_spider.py: Very simple spider to crawl through the
    online menus of the University of São Paulo :D ."""

__author__      = "Juliano Garcia de Oliveira"
__copyright__   = "Copyright NULL, Planet Earth"

import scrapy

class CardapioSpider(scrapy.Spider):
    # Spider Identifier
    name = "cardapiosSAS"
    allowed_domains = ["https://uspdigital.usp.br/"]
    start_urls = ['http://localhost:8050/render.html?url=https://uspdigital.usp.br/rucard/Jsp/cardapioSAS.jsp?codrtn=8&timeout=10&wait=0.5']

    def start_requests(self):
        # Pass request through splash
        for url in self.start_urls:
            yield scrapy.Request(url=url, callback = self.parse)

    # Process our response to the desired format
    def parse(self, response):
        # Symbol Table with key - value
        dictRest = {'8':'Física', '9':'Química'}
        # Modify this parse method
        page = dictRest[response.url.split("/")[-1][-21]]
        filename = 'c_%s.html' % page
        with open(filename, mode='wb') as f:
            f.write(response.body)
        self.log('Saved dump file %s' % filename)
