let prev_message = ''
chrome.runtime.onMessage.addListener(function(response, sender, _){
	if(prev_message !== response)
	{
		prev_message = response; 
		info = JSON.parse(response)
		console.log("For ", info[2], "\nInformation: ", info[1])
	}
});
