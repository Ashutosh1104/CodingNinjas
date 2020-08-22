<!DOCTYPE HTML>
<html lang="en">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<meta name="viewport" content="width=device-width, initial-scale=1">
<meta name="revisit-after" content="1 days">
<meta name="robots" content="index,follow">
<meta name="author" content="Sameer Gupta">
<meta name="application-name" content="Sapphire Engine">
<meta name="title" content="Sapphire Engine - Online Compiler and IDE">
<meta name="description" content="Sapphire Engine is an online compiler and debugging tool which allows you to compile, execute and share your code online. Simple, Fast and Elegant">
<meta name="keywords" content="Compiler, Interpreter, C++, c, python, ruby, JavaScript, IDE, online, online compiler, online ide, learn programming online, programming online, run code online, snippet, snippets, pastebin, online debugging tool, online interpreter, share, source code, run your code online, run code, execute code, C++, Java, Python">
<meta name="google-site-verification" content="gg3ES6gMNamp890LRyz2wKBodO6D3ytTahAoqK1FWqY" />


<meta property="og:title" content="Sapphire Engine - Online Compiler and IDE" />
<meta property="og:description" content="Sapphire Engine is an online compiler and debugging tool which allows you to compile, execute and share your code online. Simple, Fast and Elegant" />
<meta property="og:image" content=".com/img/poster.png" />
<meta property="og:url" content="https://sapphireengine.com" />
<meta property="og:site_name" content="Sapphire Engine" />
<meta property="og:type" content="website" />


<meta name="twitter:card" content="summary" />
<meta name="twitter:url" content="https://sapphireengine.com/" />
<meta name="twitter:title" content="Sapphire Engine - Online Compiler and IDE" />

<title>Sapphire Engine</title>

<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js"></script>

<link rel="stylesheet" href="css/bootstrap.min.css">
<link href='https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.css' rel='stylesheet' type='text/css'>
<link rel="shortcut icon" href="img/favicon.ico" type="image/x-icon">
<link rel="icon" href="img/favicon.ico" type="image/x-icon">

<link href='https://fonts.googleapis.com/css?family=Source+Sans+Pro' rel='stylesheet' type='text/css'>
<link href='https://fonts.googleapis.com/css?family=Cookie' rel='stylesheet' type='text/css'>

<script src="lib/codemirror.js"></script>
<script src="js/mirror.js"></script>
<script src="addon/selection/active-line.js"></script>
<script src="addon/display/placeholder.js"></script>
<script src="addon/edit/matchbrackets.js"></script>
<script src="addon/display/fullscreen.js"></script>
<script src="addon/edit/closebrackets.js"></script>
<script src="addon/hint/show-hint.js"></script>
<script src="addon/hint/anyword-hint.js"></script>
<script src="mode/ruby/ruby.js"></script>
<script src="mode/python/python.js"></script>
<script src="mode/clike/clike.js"></script>
<link rel="stylesheet" href="lib/codemirror.css">
<link rel="stylesheet" href="css/style.css">
</head>
<body>

<nav class="navbar navbar-default" style="overflow: hidden;">
<div class="container">
<div class="navbar-header">
<button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
<span class="sr-only">Toggle navigation</span>
<span class="icon-bar"></span>
<span class="icon-bar"></span>
<span class="icon-bar"></span>
</button>
<a class="navbar-brand" href="https://sapphireengine.com"><img class="logo" src="img/logo.png"></a>
</div>
<div id="navbar" class="navbar-collapse collapse">
<ul class="nav navbar-nav navbar-right">
<li><a href="#about" data-toggle="modal">About</a></li>
<li><a href="#dev" data-toggle="modal">Developer</a></li>
<li><a href="#spec" data-toggle="modal">Specification</a></li>
</ul>
</div>
</div>
</nav>

<div class="hideit">
<h1>Sapphire Engine : Online Compiler and IDE</h1>
<h2>Sapphire Engine : Online Compiler and IDE</h2>
<h3>Sapphire Engine : Online Compiler and IDE</h3>
</div>
<div class="container-fluid">
<br>
<div class="row">
<div class="col-md-1"></div>
<div class="col-md-10 col-lg-10">
<div id="codearea">
<div class="cc-editor-component row">
<div class="col-lg-3 col-md-3 col-sm-3 col-xs-5">
<select id="lang" class="form-control input-small optbtn" onchange="changemode()">
<option>C++ (g++ 5.4.0)</option>
<option>C (gcc 5.4.0)</option>
<option>Python (python 2.7.12)</option>
<option>Ruby (ruby 2.3.1)</option>
</select>
</div>
<div class="col-lg-6 col-md-6 col-sm-6 col-xs-3"></div>
<div class="col-lg-3 col-md-3 col-sm-3 c ol-xs-4">
<div class="btn-group" style="float:right;">
<button type="button" class=" optbtn btn btn-default fa fa-expand" onclick="fullscreen();">
</button>
<button type="button" id="dbtn" class=" optbtn btn btn-default fa fa-download " onclick="download();">
</button>
<button type="button" class="optbtn btn btn-default dropdown-toggle fa fa-cog " data-toggle="dropdown">
</button>
<ul class="dropdown-menu" style="padding : 13px;">
<li class="menu">
Theme :
<select id="theme" class="form-control">
<option>Light</option>
<option selected="selected">Dark</option>
<option>Materialize</option>
</select>
</li>
<li class="menu">
Font Size :
<input id="fsize" type="number" onChange="setfont(this.value);" class="form-control" value="12">
</li>
<li class="menu">
Editor Height :
<input id="hsize" type="number" onChange="setheight(this.value);" class="form-control" value="520">
</li>
</ul>
</div>
</div>
</div>
<div class="form-group" id="codeform">
<textarea class="form-control" placeholder="Code goes here..." id="code"></textarea>
</div>
</div>
<a download="info.txt" id="downloadlink" style="display: none"></a>
<div class="btn hideit" id="exit_full">
<button type="button" style="z-index: 10; position: fixed; right: 15px; top: 12px" class="btn btn-default dropdown-toggle small-editor-button fa fa-compress" onclick="exit_fullscreen();">
</button>
</div>
<div id="scrolltarget"></div>
<div class="row">
<div class="col-md-8 col-sm-6 col-xs-10" style="margin-top:5px;margin-bottom:5px;">
<input id="input-checkbox" type="checkbox" style="float:left; margin:5px;" onclick="disp_cipbox(this);"> Custom Inputs
</div>
<div class=" col-md-2 col-sm-3 col-xs-6">
<button id="cbtn" style="float:right;" type="button" class="btn btn-md btn-default utilbtn" onclick="compile();"> RUN CODE </button>
</div>
<div class=" col-md-2 col-sm-3 col-xs-6">
<button id="sbtn" style="float:right;" type="button" class="btn btn-md btn-default utilbtn" onclick="share();"> SHARE </button>
</div>
</div>
<script>
    CodeMirror.commands.autocomplete = function(cm) {
        cm.showHint({hint: CodeMirror.hint.anyword});
    }
    var editor = CodeMirror.fromTextArea(document.getElementById("code"), {
    lineNumbers: true,
    styleActiveLine: true,
    autoCloseBrackets: true,
    lineWrapping: true,
    indentUnit: 4,
    matchBrackets: true,
    theme: "monokai",
    mode: "text/x-c++src",
    extraKeys: {
        "F11": function(cm) {
            fullscreen();
        },
        "Esc": function(cm) {
          if (cm.getOption("fullScreen")) exit_fullscreen();
        },
        "Ctrl-Space": "autocomplete"
    }
    });
    editor.setValue("#include <bits/stdc++.h>\n#include <iostream>\nusing namespace std;\n\nint main()\n{\n\tcout << \"Hello World!\" << endl;\n\treturn 0;\n}");
</script>
<br>
<div class="row">
<div class="col-md-5 "></div>
<div class="col-md-2 ">
<div id="loader" class="loader hideit"></div>
</div>
<div class="col-md-5 "></div>
</div>
<div id="status" class="row hideit">
<div class="row" id="status_row">
<table class="table table-striped table-condensed">
<thead>
<tr>
<th>Code ID</th>
<th>Status</th>
<th>Time (sec)</th>
<th>Exit Signal</th>
</tr>
</thead>
<tbody>
<tr>
<td id="tcodeid"></td>
<td id="tstatus"></td>
<td id="ttime"></td>
<td id="texitvalue"></td>
</tr>
</tbody>
</table>
</div>
<br>
<div class="row" id="stdop_row">
<div id="table-wrapper">
<div id="table-scroll">
<table class="table table-striped table-condensed">
<thead>
<tr>
<th>Standard Output</th>
</tr>
</thead>
<tbody>
<tr>
<td id="tstdop" class="white"></td>
</tr>
</tbody>
</table>
</div>
</div>
</div>
</div>
<div class="row hideit" id="stderr_row">
<div id="table-wrapper">
<div id="table-scroll">
<div class="alert alert-danger">
<table class="table table-condensed">
<thead>
<tr>
<th style="border-color:#F2DEDE;">Standard Error</th>
</tr>
</thead>
<tbody>
<tr class="danger">
<td id="tstderr" class="white"></td>
</tr>
</tbody>
</table>
</div>
</div>
</div>
</div>
<div class="form-group hideit" id="inputdiv">
<textarea class="form-control" rows="5" id="input" placeholder="Write inputs of your program .. "></textarea>
</div>
<br>
</div>
<div class="col-md-1"></div>
</div>
</div>
<br>
<hr>
<footer class="footer footer-modified">
<div class="row">
<div class="col-md-12">
<p class="company" style="text-align: center;">&copy; 2018 SapphireEngine.com &nbsp;&nbsp;All Rights Reserved.</p>
<div class="footer-icons">
<a href="https://www.facebook.com/sameergupta1812" target="_blank"><i class="fa fa-facebook"></i></a>
<a href="https://twitter.com/guptasameer1812" target="_blank"><i class="fa fa-twitter"></i></a>
<a href="https://in.linkedin.com/in/sameergupta1812" target="_blank"><i class="fa fa-linkedin"></i></a>
<a href="https://github.com/sameer-gupta" target="_blank"><i class="fa fa-github"></i></a>
<a href="#mail" data-toggle="modal"><i class="fa fa-envelope" style="color: #FFFFFF;"></i></a>
</div>
</div>
</div>
</footer>

<div class="modal fade bs-example-modal-md" id="linkdetail" role="dialog">
<div class="modal-dialog modal-ls">

<div class="modal-content">
<div class="modal-body">
<button type="button" class="close" data-dismiss="modal">&times;</button>
<h4 class="modal-title" align="centre"> Shareable link :</h4>
<div class="input-group  input-group-lg " style="margin-top:10px; margin-bottom:10px;">
<input type="text" id="fin" class="form-control input-lg js-copytextarea" /><br>
<span class="input-group-btn">
<button id="cpy" class="btn input-lg js-textareacopybtn" type="button" onclick="copy()">COPY</button>
</span>
</div>
<div id="cpydiv"></div>
<div class="cent">
<div>Powered By :
<a href="http://ocul.in/" target="_blank" style="text-decoration:none;"><h4 class="oculin"> Ocul.in </h4></a>
</div>
</div>
</div>
</div>
</div>
</div>
<div class="modal fade bs-example-modal-sm" id="mail" role="dialog">
<div class="modal-dialog modal-sm">

<div class="modal-content">
<div class="modal-header">
<button type="button" class="close" data-dismiss="modal" onclick="codeform.focus()">&times;</button>
<h4 class="modal-title">Mail Us @</h4>
</div>
<div class="modal-body">
<p><a href="/cdn-cgi/l/email-protection" class="__cf_email__" data-cfemail="a2d1c3d2d2cacbd0c7c7ccc5cbccc79394e2c5cfc3cbce8cc1cdcf">[email&#160;protected]</a></p>
</div>
</div>
</div>
</div>
<div class="modal fade bs-example-modal-lg" id="about" role="dialog">
<div class="modal-dialog modal-ls">

<div class="modal-content">
<div class="modal-header" style="border:0px;padding:15px;">
<button type="button" class="close" data-dismiss="modal">&times;</button>
</div>
<div class="modal-body" style="padding:4%;padding-top:0;">
<p>
<img src="img/poster.png" class="poster">
<br><br>
Sapphire Engine is an online compiler and debugging platform which allows you to compile the source code and execute it online. High-performance and detailed analysis of code execution makes it apt for programmers.
</p>
Sapphire Engine is packed with features like :
<br>
<ul style="margin-bottom: 0;">
<li>Code Sharing</li>
<li>Customisable editor</li>
<li>Editor themes to enhance coding experience.</li>
<li>AutoBracket, AutoIndent, AutoComplete(Ctrl+Space)</li>
<li>Detailed error analysis and execution time.</li>
</ul>
</div>
</div>
</div>
</div>
<div class="modal fade bs-example-modal-md" id="dev" role="dialog">
<div class="modal-dialog modal-md">

<div class="modal-content">
<div class="modal-header">
<button type="button" class="close" data-dismiss="modal">&times;</button>
<h4 class="modal-title" align="centre">Developer</h4>
</div>
<div class="modal-body">
<img id="image" src="img/profile.png" class="img-circle">
<h4 style="text-align: center; margin:8px;">Sameer Gupta</h4>
<p style="padding-left:2%;padding-right:2%;margin-bottom:7px;">
Computer engineering student, programmer at heart and developer of Sapphire Engine. Believes in combining engineering with knowledge and passion to bring next-generation tools to developers around the world. He loves to pursue offbeat ideas.
</p>
<div class="row">
<div class="col-md-12 col-sm-12 col-xs-12">
<ul class="social-network social-circle">
<div class="btn-group " style="display:block;left: 50%; margin-left: -100px;">
<li><a href="https://www.facebook.com/sameergupta1812" target="_blank" class="icoFacebook" title="Facebook"><i class="fa fa-facebook"></i></a></li>
<li><a href="https://in.linkedin.com/in/sameergupta1812" target="_blank" class="icoLinkedin" title="Linkedin"><i class="fa fa-linkedin"></i></a></li>
<li><a href="https://twitter.com/guptasameer1812" target="_blank" class="icoTwitter" title="Twitter"><i class="fa fa-twitter"></i></a></li>
</div>
 </ul>
</div>
</div>
<br>
</div>
</div>
</div>
</div>
<div class="modal fade bs-example-modal-lg" id="spec" role="dialog">
<div class="modal-dialog modal-ls">

<div class="modal-content">
<div class="modal-header">
<button type="button" class="close" data-dismiss="modal">&times;</button>
<h4 class="modal-title" align="centre">Specification</h4>
</div>
<div class="modal-body">
<p>I/O limit : 5000 character<br>
Time limit : 5 seconds
<div class="row">
<table class="table table-striped table-condensed">
<thead>
<tr>
<th>Language</th>
<th>Version</th>
<th>Max Memory Limit</th>
</tr>
</thead>
<tbody>
<tr>
<td> C++ </td>
<td> g++ 5.4.0 </td>
<td> 256 MB </td>
</tr>
<tr>
<td> C </td>
<td> gcc 5.4.0 </td>
<td> 256 MB </td>
</tr>
<tr>
<td> Python </td>
<td> python 2.7.12</td>
<td> 256 MB </td>
</tr>
<tr>
<td> Ruby </td>
<td> ruby 2.3.1 </td>
<td> 256 MB </td>
</tr>
</tbody>
</table>
</div>
</p>
</div>
</div>
</div>
</div>

<script data-cfasync="false" src="/cdn-cgi/scripts/5c5dd728/cloudflare-static/email-decode.min.js"></script><script src="js/bootstrap.min.js"></script>
<script type="text/javascript" src="js/valid.js"></script>
<script>
var rex = " "; 
display_init(rex);
</script>
<script type="text/javascript" src="js/valid.js"></script>
<script type="text/javascript" src="js/toast.min.js"></script>
<link rel="stylesheet" href="css/toast.min.css">
<script type="text/javascript">
toastr.options = {
  "closeButton": true,
  "debug": false,
  "newestOnTop": true,
  "progressBar": false,
  "positionClass": "toast-bottom-center",
  "preventDuplicates": false,
  "onclick": null,
  "showDuration": "300",
  "hideDuration": "1000",
  "timeOut": "5000",
  "extendedTimeOut": "1000",
  "showEasing": "swing",
  "hideEasing": "linear",
  "showMethod": "fadeIn",
  "hideMethod": "fadeOut"
}
</script>
<link rel="stylesheet" href="addon/display/fullscreen.css">
<link rel="stylesheet" href="addon/hint/show-hint.css">
<link rel="stylesheet" href="theme/material.css">
<link rel="stylesheet" href="theme/monokai.css">
<div id="It's not good to hide your wounds, you know. I'm looking after you." name="-Rin"></div>
<div id="I'm never gonna give up"></div>
</body>
</html>
