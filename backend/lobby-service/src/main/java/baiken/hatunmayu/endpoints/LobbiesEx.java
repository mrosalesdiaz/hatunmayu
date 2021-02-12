package baiken.hatunmayu.endpoints;

import java.util.UUID;

import javax.inject.Inject;

import io.vertx.core.Handler;
import io.vertx.core.json.JsonObject;
import io.vertx.ext.web.RoutingContext;
import yuki.framework.dataaccess.utils.QueryExecutor;
import yuki.framework.endpoints.annotations.EndpointExtension;
import yuki.functions.FnCreateLobby;
import yuki.resources.GetLobbies;

@EndpointExtension(GetLobbies.class)
public class LobbiesEx implements Handler<RoutingContext> {

	@Inject
	private QueryExecutor queryExecutor;

	@Override
	public void handle(final RoutingContext rc) {
		
		FnCreateLobby fnCreateLobby=queryExecutor.create(FnCreateLobby.class);
		
		fnCreateLobby.setAdmin_uuid(UUID.randomUUID());
		fnCreateLobby.setNickname("patito");
		fnCreateLobby.setName("sandbox");
		fnCreateLobby.setSecret("secure");
		
		fnCreateLobby.execute().onSuccess(h->{

			rc.response()
					.end(h.toString());	
		});
		
	}

}
