function Messages(suite, test){
	this.suite=suite;
	this.test=test;
}
Messages.prototype.ShowTest = function() {
	return "Suite #"+this.suite+":"+"Test #"+this.test+" : ";
};
Messages.prototype.ResultOk = function(process) {
	process.send({ msg: this.ShowTest()+"Result OK" });
};
Messages.prototype.Fail = function(process, msg) {
	process.send({ msg: this.ShowTest()+"Fail: "+msg });
};
Messages.prototype.Error = function(process, msg) {
	process.send({ msg: this.ShowTest()+"Error: "+msg });
};
exports.Messages = Messages;

function Manager(dir) {
	this.dir=dir;
	this.manage;
	this.msg;
	this.pause;
	this.repeat;
}	
Manager.prototype.FindLibPath = function() {
	var path = this.dir;
	var index = path.indexOf("jtrs");
	path = path.substring(0, index+5);
	return path;
}
Manager.prototype.StartTest = function (fun){
	var dir=this.dir;
	var os = require('os');	
	if (os.platform()=="win32") {
		var manageapp = require(this.FindLibPath()+"lib/Win/ApplicationManagementWin");
		manage = new manageapp.ApplicationManagement();
		var fileSystem = require("fs");
    	var xml2js = require(this.FindLibPath()+'xml2js/node_modules/xml2js'); 
    	fileSystem.readdirSync(dir).forEach(function(file) {
        	file = dir+'/'+file;
        	var stat = fileSystem.statSync(file);
        	if(file.split('.').pop()=='xml') {
            	var parser = new xml2js.Parser();  
            	fileSystem.readFile(file, function(err, data) {
                	parser.parseString(data, function (err, result) {
                		pause=Number(result.suite.test[0].repeat[0].$.pause);
                		repeat=Number(result.suite.test[0].repeat[0]._);
                		manage.SetAppName(String(result.suite.application));
                		manage.SetWindowName(String(result.suite.windowName));
                		msg = new Messages(result.suite.$.name, result.suite.test[0].$.name);
						setTimeout(fun,100, this);
                	});
            	});
        	}
    	});
	}
	else {
		console.log("Operating system not supported");
	}
}

exports.Manager = Manager;