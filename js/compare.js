(function($)  {
	function comparefunction(context)  {
//		$(document).ready(function(){
//			$("#content").prepend("<div id='compare_block'><img id='image1' height='50px' width='50px' /><img id='image2' height='50px' width='50px' /><img id='image3' height='50px' width='50px' /><img id='image4' height='50px' width='50px' /><a id='aclose'>Close</a><button id='btn_compare'>Compare</button></div>");
//			$("#compare_block").addClass("compare_block_css");
//			$("#image1").addClass("image");
//			$("#image2").addClass("image");
//			$("#image3").addClass("image");
//			$("#image4").addClass("image");
//			$("#aclose").addClass("close_button");
//			var flag_item1 = null;
//			var flag_item2 = null;
//			var flag_item3 = null;
//			var flag_item4 = null;
			var checkbox_id;
			var count = 0;
			var compare_count = 0;
			
			document.getElementById("btn_compare").disabled = true;
			
			$(".compare").live("click", function(){
//				alert($(this).attr("id"));
//				if (Drupal.ajax)	{
				var checkbox_id = $(this).attr("id");
				$(this).attr("disabled", true);
				
				var item = document.getElementById("compare_item");
//				alert(item.id);
				item.id = checkbox_id;
				
				count++;
				compare_count++;
				
//				alert(count);
				if (count == 4)	{
//					alert(count);
					$(":checkbox").attr("disabled", true);
				}
				btn_compare_check_enabled();
//				alert(item.id);
			
//				document.getElementById(checkbox_id).disabled = true;
//				
//				var x = document.getElementsByName("compare_item");
//				var i;
//				for (i in x){
//					if ((x[i].id == "compare_item") && (count == 0)){
//						x[i].id = checkbox_id;
//						count++;
//					}
//					alert(x[i].id);
//				}
//				count = 0;
//				$("div.div_image").each(function(){
//					if (!($("div.div_image").attr("id")) && (count == 0)){
//						$("div.div_image").attr("id", checkbox_id);
//						count++;
//					}
//					else{
//						return false;
//					}
//					alert(count);
//				});
//				
//				count = 0;
				
				$.ajax({
						type: "GET",
						url: Drupal.settings.basePath + '/get_image',
						dataType: 'json',
						data: "id=" + encodeURI(checkbox_id),
						success: function(result){
//							item.innerHTML("<img width='50px' height='50px' class='image' src='/compare/sites/default/files/add_item.jpg'><span id='remove_item1' class='remove_item'></span>");
//							if (!($("#image1").attr("src"))) {
//								$("#image1").attr("src", Drupal.settings.basePath + "sites/default/files/" + result);
//							}
//							else if (!($("#image2").attr("src"))) {
//								$("#image2").attr("src", Drupal.settings.basePath + "sites/default/files/" + result);
//							}
//							else if (!($("#image3").attr("src"))) {
//								$("#image3").attr("src", Drupal.settings.basePath + "sites/default/files/" + result);
//							}
//							else if (!($("#image4").attr("src"))) {
//								$("#image4").attr("src", Drupal.settings.basePath + "sites/default/files/" + result);
//							}
//							if (flag_item1 == null){
//								$("#item1").html("<img id='image1' class='image' height='50px' width='50px' /><img class='remove_item' src='/compare/sites/default/files/close_button.jpg' />");
								
								var image_element = document.getElementById(item.id).getElementsByTagName("img");
								var span_element = document.getElementById(item.id).getElementsByTagName("span");
//								alert(image_element + span_element);
								image_element[0].setAttribute("src", Drupal.settings.basePath + "sites/default/files/" + result);
//								span_element[0].style.display = "block";
								span_element[0].setAttribute("title", "Remove");
								span_element[0].innerHTML = "<img src='/compare/sites/default/files/close_button.jpg' />";
								
//								$("#"+item.id).find("img").attr("src", Drupal.settings.basePath + "sites/default/files/" + result);
//								$("#"+item.id).find("span").append("<img src='/compare/sites/default/files/close_button.jpg' />");
//								$("#"+(item.id)).attr("disabled", true);
//								
//								$("#image1").attr("src", Drupal.settings.basePath + "sites/default/files/" + result);
//								document.getElementById("remove_item1").innerHTML = "<img src='/compare/sites/default/files/close_button.jpg' />";
//								
//								flag_item1 = checkbox_id;
//								document.getElementsByName("compare_item").id = checkbox_id;
//							}
//							if (flag_item2 == null){
////								$("#item2").html("<img id='image2' class='image' height='50px' width='50px' />");
//								
//								$("#image2").attr("src", Drupal.settings.basePath + "sites/default/files/" + result);
//								document.getElementById("remove_item2").innerHTML = "<img src='/compare/sites/default/files/close_button.jpg' />";
//								
//								flag_item2 = checkbox_id;
//							}
//							else if (flag_item3 == null){
////								$("#item3").html("<img id='image3' class='image' height='50px' width='50px' /><img class='remove_item' src='/compare/sites/default/files/close_button.jpg' />");
//								
//								$("#image3").attr("src", Drupal.settings.basePath + "sites/default/files/" + result);
//								document.getElementById("remove_item3").innerHTML = "<img src='/compare/sites/default/files/close_button.jpg' />";
//								
//								flag_item3 = checkbox_id;
//							}
//							else if (flag_item4 == null){
////								$("#item4").html("<img id='image4' class='image' height='50px' width='50px' /><img class='remove_item' src='/compare/sites/default/files/close_button.jpg' />");
//								
//								$("#image4").attr("src", Drupal.settings.basePath + "sites/default/files/" + result);
//								document.getElementById("remove_item4").innerHTML = "<img src='/compare/sites/default/files/close_button.jpg' />";
//								
//								flag_item4 = checkbox_id;
//							}
//					document.write(result);
					}
				
				});
//					var frmDrupal = function(data)	{
//						var result = Drupal.parseJson(data);
//						$("#compare_block").html(result);
//					};
//					$.get('/compare/get_image', $(this).attr("id"), frmDrupal);
//					return false;
//				}
//				if (!Drupal.ajax)	{
//					document.write("no ajax called");
//				}
				$("#compare_cart").slideDown(500, function(){
					$(this).css("display", "static");
					$(this).css("position", "relative");
					$(this).css("top", "25%");
				}); 
//				function(){
//					$("#compare_block").css("display", "block");
//					$("#compare_block").css("position", "relative");
//					$("#compare_block").css("top", "0");
//				});
				
//				if (flag_item4 == false){
//					$(":checkbox").attr("disabled", true);
//				}
				
			});
			
			$(".remove_item").live('click', function(){
//				$(this).css("display", "none");
				$(this).hide("fast", function(){
					var id = $(this).parent().attr("id");
//					alert(id);
					var remove_item_id = document.getElementById(id);
					$("div#"+id).remove();
//					$("div#"+id).children("img").attr("src", "/compare/sites/default/files/add_item.jpg");
//					$("div#"+id).children("span").children("img").remove();
//					$("div#"+id).attr("id", "compare_item");
//					var compare_block_element = document.getElementById("compare_block");
//					
//					compare_block_element.removeChild(remove_item_id);
//					compare_block_element = $("#compare_block");
//					compare_block_element.attr("id", "compare_block");
//					var new_image_element = document.createElement("img");
//					new_image_element.setAttribute("src", "/compare/sites/default/files/add_item.jpg");
//					new_image_element.setAttribute("height", "50px");
//					new_image_element.setAttribute("width", "50px");
//					
//					var new_span_element = document.createElement("span");
//					new_span_element.className = "remove_item";
					
//					var new_compare_item = document.createElement("div");
//					new_compare_item.setAttribute("id", "compare_item");
//					new_compare_item.className = "div_image";
//					new_compare_item.setAttribute("name", "compare_item");
					
					new_compare_item = $("<div/>");
					new_compare_item.attr("id", "compare_item");
					new_compare_item.attr("name", "compare_item");
					new_compare_item.addClass("div_image");
					new_compare_item.append($("<img/>")
							.addClass("image")
							.attr("src", "/compare/sites/default/files/add_item.jpg")
							.attr("height", 50)
							.attr("width", 50));
					
					new_compare_item.append($("<span/>")
							.addClass("remove_item")
							.click(function(){
								$(this).parent().remove();
							}));
					
//					new_compare_item.appendChild($("<span/>")
//							.addClass("remove_item")
//							.click(function(){
//								$(this).parent().remove();
//							})
//							).append($("<img/>")).attr("src", "/compare/sites/default/files/close_button.jpg");
//					new_compare_item.innerHTML = "<img width='50px' height='50px' class='image' src='/compare/sites/default/files/add_item.jpg'>";
//					new_compare_item.appendChild(new_image_element);
//					new_compare_item.appendChild(new_span_element);
//					new_compare_item.innerHTML = "<img width='50px' height='50px' class='image' src='/compare/sites/default/files/add_item.jpg'><span title='Remove' class='remove_item'></span>";
//					alert(new_compare_item);
					$("#compare_block").append(new_compare_item);
					
					$("input#"+id).attr("disabled", false);
					$("input#"+id).attr("checked", false);
					
					count--;
					compare_count--;
					
					btn_compare_check_enabled();
					$(":checkbox").each(function(){
						if (($(this).attr("checked")) == false){
							$(this).attr("disabled", false);
						}
					});
				});
//				var this_id = $(this).attr("id");
//				container_id = this_id.charAt(this_id.length - 1);
//				
//				var flag_item_id = "flag_item" + container_id;
//				
//				var item_id = flag_item_id;
//				
//				alert(item_id);
//				document.getElementById(this_id).innerHTML = "";
//				
//				$(this).prev().attr("src", "/compare/sites/default/files/add_item.jpg");
				
//				$(":disabled").attr("disabled", false);
//				$(":checked").attr("checked", false);
			});
			
			function reset_compare_list(){
//				var compare_items = document.getElementsByName("compare_item");
//				for (item in compare_items){
//					compare_items[item].id = "compare_item";
////					compare_items[item].name = "compare_item";
//					compare_items[item].innerHTML = "<img width='50px' height='50px' class='image' src='/compare/sites/default/files/add_item.jpg' /><span class='remove_item'></span>";
//				}
//				alert("hello");
				count = 0;
				compare_count = 0;
				
				
				$("[name='compare_item']").each(function(index){
//					alert(index);
					$(this).attr("id", "compare_item");
					$(this).children("img").attr("src", "/compare/sites/default/files/add_item.jpg");
					$(this).children("span").children("img").remove();
//					$(this).append("<img width='50px' height='50px' class='image' src='/compare/sites/default/files/add_item.jpg' /><span class='remove_item'></span>");
				});
				$(":disabled").attr("disabled", false);
				$(":checked").attr("checked", false);
			}
			
			$("#aclose").click(function(){
//				$("#item1").html("<img src='/compare/sites/default/files/add_item.jpg' />");
//				$("#item2").html("<img src='/compare/sites/default/files/add_item.jpg' />");
//				$("#item3").html("<img src='/compare/sites/default/files/add_item.jpg' />");
//				$("#item4").html("<img src='/compare/sites/default/files/add_item.jpg' />");
				
				
//				flag_item1 = true;
//				flag_item2 = true;
//				flag_item3 = true;
//				flag_item4 = true;
				reset_compare_list();
				btn_compare_check_enabled();
				$("#compare_cart").slideUp(100);
			});
			
			$("#aclearlist").click(function(){
				reset_compare_list();
				btn_compare_check_enabled();
			});
			
			function btn_compare_check_enabled(){
				if (compare_count >= 2) {
					document.getElementById("btn_compare").disabled = false;
				}
				else {
					document.getElementById("btn_compare").disabled = true;
				}
				return;
			}
			
//		});
	}
	
	Drupal.behaviors.compare = {
			attach: function(context)  {
				comparefunction(context);
			}
	};
})(jQuery);