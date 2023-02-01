import requests

cookies = {
    '__gads': 'ID=ca43cd4972eb1954-22a684ce46db0040:T=1673641417:RT=1673641417:S=ALNI_MaZozpyY0fxPmQOd6VuHjRbtIHD5Q',
    'ASP.NET_SessionId': 'dai3natmvoaletrhqnj5d35x',
    'ZPUSOB_OVERENI': 'SOL',
    'SERVERID': 'S-WEB-03',
    'cookieconsent_sol': '{"level":["necessary","analytics"],"revision":0,"data":null,"rfc_cookie":false}',
    '__utma': '202636225.1772573772.1673641433.1673641433.1673641433.1',
    '__utmc': '202636225',
    '__utmz': '202636225.1673641433.1.1.utmcsr=(direct)|utmccn=(direct)|utmcmd=(none)',
    'SESSION_EXPIRES': '2023-01-15T21:31:16',
    '.ASPXAUTH': 'E8301FC406BF0799EE42282323DC401A75D942ACDE263F3126117692A39DE72A4C509EBD4A15BCB41A5C06560C07417EB8A91A6A212D25E82AFF49A29FDEBE2ED5BAD04410690A6C4B4A544C188E34F01A8886ED',
    '__gpi': 'UID=00000ba21e8ac7ce:T=1673641417:RT=1673912046:S=ALNI_Ma_c0CscHwZmCdKjUGodVTDaqf6rg',
}

headers = {
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
    'Accept-Language': 'cs,en-US;q=0.9,en;q=0.8',
    'Cache-Control': 'max-age=0',
    'Connection': 'keep-alive',
    'Content-Type': 'multipart/form-data; boundary=----WebKitFormBoundaryitIf4JRDj2yjtrg8',
    # 'Cookie': '__gads=ID=ca43cd4972eb1954-22a684ce46db0040:T=1673641417:RT=1673641417:S=ALNI_MaZozpyY0fxPmQOd6VuHjRbtIHD5Q; ASP.NET_SessionId=dai3natmvoaletrhqnj5d35x; ZPUSOB_OVERENI=SOL; SERVERID=S-WEB-03; cookieconsent_sol={"level":["necessary","analytics"],"revision":0,"data":null,"rfc_cookie":false}; __utma=202636225.1772573772.1673641433.1673641433.1673641433.1; __utmc=202636225; __utmz=202636225.1673641433.1.1.utmcsr=(direct)|utmccn=(direct)|utmcmd=(none); SESSION_EXPIRES=2023-01-15T21:31:16; .ASPXAUTH=E8301FC406BF0799EE42282323DC401A75D942ACDE263F3126117692A39DE72A4C509EBD4A15BCB41A5C06560C07417EB8A91A6A212D25E82AFF49A29FDEBE2ED5BAD04410690A6C4B4A544C188E34F01A8886ED; __gpi=UID=00000ba21e8ac7ce:T=1673641417:RT=1673912046:S=ALNI_Ma_c0CscHwZmCdKjUGodVTDaqf6rg',
    'Origin': 'https://www.skolaonline.cz',
    'Referer': 'https://www.skolaonline.cz/',
    'Sec-Fetch-Dest': 'document',
    'Sec-Fetch-Mode': 'navigate',
    'Sec-Fetch-Site': 'same-site',
    'Sec-Fetch-User': '?1',
    'Upgrade-Insecure-Requests': '1',
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 Safari/537.36 OPR/93.0.0.0',
    'sec-ch-ua': '"Opera GX";v="93", "Not/A)Brand";v="8", "Chromium";v="107"',
    'sec-ch-ua-mobile': '?0',
    'sec-ch-ua-platform': '"macOS"',
}

data = '------WebKitFormBoundaryitIf4JRDj2yjtrg8\r\nContent-Disposition: form-data; name="__EVENTTARGET"\r\n\r\ndnn$ctr994$SOLLogin$btnODeslat\r\n------WebKitFormBoundaryitIf4JRDj2yjtrg8\r\nContent-Disposition: form-data; name="__EVENTARGUMENT"\r\n\r\n\r\n------WebKitFormBoundaryitIf4JRDj2yjtrg8\r\nContent-Disposition: form-data; name="__VIEWSTATE"\r\n\r\nGExO5x20l1SQTwoUdltTZP1v7KeKBEO62lCZllK03RrL3KCi5iFzP5/iLMqo3O7K0AZh6iv/H5fCcWwe2VsYrLQSosOnM/Jn47mUVTVypQ0ixK6nDXNE91mG88R6F8kzAC3Uie5a22xejvf+qO6raWISkMlk3CyFD66Vg2MArL/V7PyLvOwFr8MypHrRgvsZpLmfB0NCWrOc03fAcjYG3O3xMh8=\r\n------WebKitFormBoundaryitIf4JRDj2yjtrg8\r\nContent-Disposition: form-data; name="__VIEWSTATEGENERATOR"\r\n\r\nCA0B0334\r\n------WebKitFormBoundaryitIf4JRDj2yjtrg8\r\nContent-Disposition: form-data; name="__VIEWSTATEENCRYPTED"\r\n\r\n\r\n------WebKitFormBoundaryitIf4JRDj2yjtrg8\r\nContent-Disposition: form-data; name="__PREVIOUSPAGE"\r\n\r\nKNiZiHexPoUgUZeWN_UPIMyzq4gGnSP02SQmlSvk3VjxztC8Pnc0wob4Lp81\r\n------WebKitFormBoundaryitIf4JRDj2yjtrg8\r\nContent-Disposition: form-data; name="__EVENTVALIDATION"\r\n\r\nm+j/ivCgU3JYI8SjOtKUSiD07RxYLuKF+Vu5YD8WvsDESzhtmZBa5t1buD9/rhA0tVFS+b78JjwPhGeWUFzuL+b2cg1gEyvrBkHX2nQ3wEFuJqXV4+g5U5eV1fx3B8wCOz3mvH5bkxoUbkf+PHEDBVeMaKUcI/xHTrQjAXYkeOTjcvIh\r\n------WebKitFormBoundaryitIf4JRDj2yjtrg8\r\nContent-Disposition: form-data; name="dnn$dnnSearch$txtSearch"\r\n\r\n\r\n------WebKitFormBoundaryitIf4JRDj2yjtrg8\r\nContent-Disposition: form-data; name="JmenoUzivatele"\r\n\r\nandrysekj\r\n------WebKitFormBoundaryitIf4JRDj2yjtrg8\r\nContent-Disposition: form-data; name="HesloUzivatele"\r\n\r\nB6@Sko2e\r\n------WebKitFormBoundaryitIf4JRDj2yjtrg8\r\nContent-Disposition: form-data; name="ScrollTop"\r\n\r\n\r\n------WebKitFormBoundaryitIf4JRDj2yjtrg8\r\nContent-Disposition: form-data; name="__dnnVariable"\r\n\r\n`{`__scdoff`:`1`,`sf_siteRoot`:`/`,`sf_tabId`:`444`}\r\n------WebKitFormBoundaryitIf4JRDj2yjtrg8\r\nContent-Disposition: form-data; name="__RequestVerificationToken"\r\n\r\nh2TpPQqRYcJZiPE-ywE3Uczqu3HWzwseW32q_JisIRHRdnLICyKsayVJme4JjgvWBlyltg2\r\n------WebKitFormBoundaryitIf4JRDj2yjtrg8--\r\n'

response = requests.post('https://aplikace.skolaonline.cz/SOL/Prihlaseni.aspx', cookies=cookies, headers=headers,
                         data=data)

print(response.text)
