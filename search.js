


/*
	Muhammad Haseeb
	2020-10-0192

	
	Al  cases of lower case letters or upper case letter are efficeintly handled. Even punctuations ['-',',','.','!'] are
	handled. So It is a good practical code. 
	I have not used rejections of promises. But I have handled cases in a way that there will be never any rejection.

*/








const fs = require('fs')
const path = require('path')



const mode = process.argv[2]
const jsonFile = process.argv[3]




if(mode == 'index'){
	const headDirectory = process.argv[4]
	allDirectories = []
	allFilesDictionary = {}
	allFiles = []

	indexDix = {}

	parsedDictionary = {} 
	parsedFiles = []
	parsedByWords = []
	/*Function to read all providedDirectory*/
	readMyDir = (dirToRead)=>{
		files = fs.readdirSync(dirToRead)
		txtFiles = []
		files.forEach(f =>{
			ff = path.join(dirToRead,f)
			if(fs.lstatSync(ff).isDirectory()){
				allDirectories.push(ff)
			}
			else{
				allFiles.push(ff)
				txtFiles.push(ff)
			}
		})
		allFilesDictionary[dirToRead] = txtFiles
	}



	readAllFiles = (listOfFiles)=> new Promise(res =>{
		count = listOfFiles.length
		listOfFiles.forEach(l => new Promise(resolve =>{
			fs.readFile(l,'utf-8',(err,data)=>{
				if(err)
					console.log("error")
				console.log(`parsed ${l}`)
				fil = data.split('\n')
				word = data.split(" ")
				parsedByWords = parsedByWords.concat(word)
				parsedDictionary[l] = fil
				parsedFiles = fil
				resolve()
				if(--count == 0){
					res()
				}
			})
		}))
	})

	cropWords = (listOfWords)=> new Promise(resolve =>{
		newList = []
		f=0
		listOfWords.forEach(word =>{
			word = word.replace('\n'," ")
			word = word.replace('\n'," ")
			arr = word.split(" ")
			arr.forEach(i=>{
				f = 1
				i = i.replace('.',"")
				i = i.replace('!',"")
				i = i.replace(',',"")
				i = i.replace('-',"")
				newList.push(i)
			})
			if(f==0){
				word = word.replace(',',"")
				word = word.replace('!',"")
				word = word.replace('.',"")
				word = word.replace('-',"")
				newList.push(word)
			}
		})
		parsedByWords = []
		parsedByWords = newList
		resolve()
	})


	auxIndex = (word, keys, linesDictionary) => new Promise(resolve=>{
		localDixList = []
		for(i=0; i< keys.length; i++){
			list = []
			for(j=0; j< linesDictionary[keys[i]].length; j++){
				if((linesDictionary[keys[i]])[j].indexOf(word) != -1 || (((linesDictionary[keys[i]])[j]).toLowerCase()).indexOf(word.toLowerCase()) != -1 ){
					list.push(j)
					// console.log((linesDictionary[keys[i]])[j])
					// console.log(` searching  ${word}`)
				}
			}
			
			if(list.length!=0){
				localDix = {"file" : keys[i], "line" : list}
				localDixList.push(localDix)
			}
		}
		indexDix[(word).toLowerCase()] = localDixList
		resolve();
	})
	indexWords = (words, linesDictionary) => new Promise(resolve=>{
		keys = Object.keys(linesDictionary)
		count = 1
		parsedByWords.forEach(w=>{
			if(w.length > 2){
					auxIndex(w,keys,linesDictionary).then(()=>{
					//console.log(` ${count++} word(s) Indexed`)
				})
			}
		})
		resolve()
	})
	/*main()*/
	allDirectories.push(headDirectory)
	for(i=0; i< allDirectories.length;i++){
		readMyDir(allDirectories[i])
	}


	readAllFiles(allFiles).then(()=>{
		set = new Set(parsedByWords)
		array = Array.from(set)
		parsedByWords = []
		parsedByWords = array
		
		cropWords(parsedByWords).then(()=>{
			console.log("croped")
		})

		indexWords(parsedByWords, parsedDictionary).then(()=>{
			console.log("Indexed")
			finalJson = JSON.stringify(indexDix)
			//console.log(finalJson)
			fs.writeFile(jsonFile,finalJson,err =>{
				if(!err)
				console.log('JSON FILE IS READY')
			})
		})

	})
}
else if (mode == 'search'){
	const words2Search = JSON.parse(process.argv[4])

	results = []
	jsonsDictionary = {}

	funcToRead = () => new Promise(resolve =>{
		fs.readFile(jsonFile,(err,data)=>{
			if(!err){
				jsonsDictionary = JSON.parse(data)
				console.log('file parsed')
			}
			resolve()
		})
		
	})


	showResult = (list,w) => new Promise(resolve =>{
		count = list.length
		if(count == 0)
			resolve()
		list.forEach(dict =>{
			f = dict["file"]

			fs.readFile(f,'utf-8',(err,data)=>{
				adata = data.split('\n')
				l = dict["line"]
				l.forEach(li=>{
					console.log(adata[li])
					console.log('\n')
				})

				if(--count == 0){
					resolve();
				}

			})

		})

	})


	funcToRead().then(()=>{
		words2Search.forEach(w=>{
			w = w.toLowerCase()
			w = w.replace('.','')
			w = w.replace('!','')
			w = w.replace(',','')
			keys = Object.keys(jsonsDictionary)
			flag = 0
			keys.forEach(k=>{
				if (k.toLowerCase() == w){
					flag = 1
				}
			})
			if(flag == 0){
				console.log(`Sorry, No prominent results for ${w}`)
				console.log('\n')
			}
			else{
				lis = jsonsDictionary[w]
				showResult(lis,w).then(()=>{
				})
			}
		})
	})


}

