var city='';
var state=0;

var APIKey='b0adae584a044dcebc5b47502cf1e63e';

var loadWeather=function(jsonResponse){
	console.log(jsonResponse);

	// if(jsonResponse.response.error){
	// 	alert(jsonResponse.response.error.description);
	// 	return;
	// }
    
    var thisCity=jsonResponse.rates[city];
    var money=thisCity*state
    // var temp=jsonResponse.rates.;
    // var weather=jsonResponse.current_observation.weather;
    // var icon=jsonResponse.thumbnail.path;

    console.log("this is city"+money);

    $('.temperature').html(thisCity);
    // $('.weather').html(weather);
    // $('.weatherIcon').html('<img src="'+icon+'/portrait_fantastic.jpg">');
    $('currentCity').val(thisCity);

}


var setLocation=function(){
	city=$('.currentState').val();
	console.log(city);
	state=$('.currentCity').val();
	// console.log("City is:"+city+"state is:"+state);

	if(city==null||city==''){
		alert('hey jude');
		return;
	}
	getWeather();
}


var getWeather=function(){
	// var myUrl="http://gateway.marvel.com:80/v1/public/characters?name="+city+"&apikey="+APIKey;

		var myUrl="https://openexchangerates.org/api/latest.json?app_id="+APIKey;
    console.log(myUrl);

    $.ajax({
    	url:myUrl,
    	dataType:"jsonp",
    	success:function(response){
    		console.log("i got");
    		loadWeather(response);
    	}
    });
}

var init =function(){
	console.log("Hello World");

	$("#submit").click(function(event){
		event.preventDefault();
		setLocation();
	});
}

$(document).ready(function(){
	init();
});