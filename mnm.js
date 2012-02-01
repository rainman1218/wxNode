#!/usr/bin/env node

var path = require('path');
var childProcess = require('child_process');
var Builder = require('mnm');
var builder = new Builder();

builder.appendUnique('CXXFLAGS', ['-Isrc/']);

function build(wxCxxFlags, wxLibs) {
  builder.appendUnique('CXXFLAGS', wxCxxFlags);
  builder.appendUnique('LINKFLAGS', wxLibs);

  builder.target = "wxnode_bindings";
  builder.appendSourceDir('./src');
  builder.appendUnique('CXXFLAGS', '-Isrc/');
  builder.appendSourceDir('./src-generated');
  builder.appendUnique('CXXFLAGS', '-Isrc-generated/');

  builder.run();
}

// get the wx command line flags
runCommandLine('wx-config', ['--cxxflags'], function(err, wxCxxFlags) {
  if(err) { builder.fail(err); return; }
  runCommandLine('wx-config', ['--libs'], function(err, wxLibs) {
    if(err) { builder.fail(err); return; }
    build(wxCxxFlags, wxLibs);
  });
});

String.prototype.trim = function() {
	return this.replace(/^\s+|\s+$/g,"");
}

function runCommandLine(cmd, args, callback) {
  var results = "";
  var child = childProcess.spawn(cmd, args);
  child.stdout.on('data', function (data) {
    results += data;
  });
  child.stderr.on('data', function (data) {
    results += data;
  });
  child.on('exit', function(code) {
    callback(code, results.trim().split(' ').filter(function(item) { return item.length > 0; }));
  });
}
