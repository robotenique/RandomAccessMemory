#!/usr/bin/env python

"""cardapios_spider.py: Very simple spider to crawl through the
    online menus of the University of São Paulo :D ."""

__author__      = "Juliano Garcia de Oliveira"
__copyright__   = "Copyright NULL, Planet Earth"

import scrapy
from scrapy_splash import SplashRequest
# Color constants
W  = '\033[0m'  # white (normal)
R  = '\033[31m' # red
G  = '\033[32m' # green
O  = '\033[33m' # orange
B  = '\033[34m' # blue
P  = '\033[35m' # purple


class CardapioSpider(scrapy.Spider):
    # Spider Identifier
    name = "cardapiosSAS"
    allowed_domains = ["https://uspdigital.usp.br/"]
    start_urls = [f"https://uspdigital.usp.br/rucard/Jsp/cardapioSAS.jsp?codrtn={i}"
                  for i in range(7, 10)]

    def start_requests(self):
        # Pass request through splash
        for url in self.start_urls:
            yield SplashRequest(url=url, callback=self.parse,
            args={
            'wait': 5,})

    # Process our response to the desired format
    def parse(self, response):
        # Symbol Table with key - value
        dictRest = {"7":"Prefeitura" , "8":"Física", "9":"Química"}
        # Modify this parse method
        print(P)
        print(response.body)
        print(W)
        page = dictRest[response.url.split("/")[-1][-1]]
        filename = "c_%s.html" % page
        with open(filename, mode="wb") as f:
            f.write(response.body)
        self.log("Saved dump file %s" % filename)
