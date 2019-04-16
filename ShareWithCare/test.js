document.addEventListener('click', function(e) {
    if(document.domain === 'docs.google.com')
    {
        e = e || window.event;
        var target = e.target || e.srcElement,
            text = target.textContent || target.innerText;
            
        var obj = document.evaluate('//*[@id="docs-titlebar-share-client-button"]/div', document, null, XPathResult.FIRST_ORDERED_NODE_TYPE, null).singleNodeValue;
        var name = document.evaluate('//*[@id="docs-title-widget"]/input', document, null, XPathResult.FIRST_ORDERED_NODE_TYPE, null).singleNodeValue;
        if(obj != null) {
            console.log(obj.getAttribute('aria-label'));
            shInf = obj.getAttribute('aria-label') || 'not found'
            nmInf = name.getAttribute('value') || 'not found'
            info = {1:shInf, 2: nmInf}
            chrome.runtime.sendMessage(JSON.stringify(info))
        }
    }
}, false);
