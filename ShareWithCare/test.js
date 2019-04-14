document.addEventListener('click', function(e) {
    if(document.domain === 'docs.google.com')
    {
        e = e || window.event;
        var target = e.target || e.srcElement,
            text = target.textContent || target.innerText;
            
        var obj = document.evaluate('//*[@id="docs-titlebar-share-client-button"]/div', document, null, XPathResult.FIRST_ORDERED_NODE_TYPE, null).singleNodeValue;
        if(obj != null) {
            console.log(obj.getAttribute('aria-label'));
            info = obj.getAttribute('aria-label') || 'not found'
            chrome.runtime.sendMessage(info)
        }
    }
}, false);